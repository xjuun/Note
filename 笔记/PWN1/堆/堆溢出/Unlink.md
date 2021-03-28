[TOC]

## unlink介绍

unlink用来将一个双向链表中的一个chunk取出来，可能在以下地方使用：

-   malloc
    -   从恰好合适的large bin中获取chunk
        -   这里需要注意的是fast bin与small bin没有使用unlink，这就是为什么漏洞会经常出现在这里。
        -   依次遍历处理unsorted bin时也没有使用unlink
    -   从比请求的chunk所在的bin大的bin中取chunk
-   free
    -   向后合并，合并物理相邻低地址空闲的chunk
    -   向前合并，合并物理相邻高地址空闲chunk（除top chunk）
-   malloc_consolidate
    -   向后合并，合并物理相邻低地址空闲的chunk
    -   向前合并，合并物理相邻高地址空闲chunk（除top chunk）
-   realloc
    -   向前扩展，合并物理相邻高地址空闲chunk（除top chunk）

unlink被实现为了一个宏：

```c
/* Take a chunk off a bin list */
// unlink p
#define unlink(AV, P, BK, FD) {                                            \
    // 由于 P 已经在双向链表中，所以有两个地方记录其大小，所以检查一下其大小是否一致。
    if (__builtin_expect (chunksize(P) != prev_size (next_chunk(P)), 0))      \
      malloc_printerr ("corrupted size vs. prev_size");               \
    FD = P->fd;                                                                      \
    BK = P->bk;                                                                      \
    // 防止攻击者简单篡改空闲的 chunk 的 fd 与 bk 来实现任意写的效果。
    if (__builtin_expect (FD->bk != P || BK->fd != P, 0))                      \
      malloc_printerr (check_action, "corrupted double-linked list", P, AV);  \
    else {                                                                      \
        FD->bk = BK;                                                              \
        BK->fd = FD;                                                              \
        // 下面主要考虑 P 对应的 nextsize 双向链表的修改
        if (!in_smallbin_range (chunksize_nomask (P))                              \
            // 如果P->fd_nextsize为 NULL，表明 P 未插入到 nextsize 链表中。
            // 那么其实也就没有必要对 nextsize 字段进行修改了。
            // 这里没有去判断 bk_nextsize 字段，可能会出问题。
            && __builtin_expect (P->fd_nextsize != NULL, 0)) {                      \
            // 类似于小的 chunk 的检查思路
            if (__builtin_expect (P->fd_nextsize->bk_nextsize != P, 0)              \
                || __builtin_expect (P->bk_nextsize->fd_nextsize != P, 0))    \
              malloc_printerr (check_action,                                      \
                               "corrupted double-linked list (not small)",    \
                               P, AV);                                              \
            // 这里说明 P 已经在 nextsize 链表中了。
            // 如果 FD 没有在 nextsize 链表中
            if (FD->fd_nextsize == NULL) {                                      \
                // 如果 nextsize 串起来的双链表只有 P 本身，那就直接拿走 P
                // 令 FD 为 nextsize 串起来的
                if (P->fd_nextsize == P)                                      \
                  FD->fd_nextsize = FD->bk_nextsize = FD;                      \
                else {                                                              \
                // 否则我们需要将 FD 插入到 nextsize 形成的双链表中
                    FD->fd_nextsize = P->fd_nextsize;                              \
                    FD->bk_nextsize = P->bk_nextsize;                              \
                    P->fd_nextsize->bk_nextsize = FD;                              \
                    P->bk_nextsize->fd_nextsize = FD;                              \
                  }                                                              \
              } else {                                                              \
                // 如果在的话，直接拿走即可
                P->fd_nextsize->bk_nextsize = P->bk_nextsize;                      \
                P->bk_nextsize->fd_nextsize = P->fd_nextsize;                      \
              }                                                                      \
          }                                                                      \
      }                                                                              \
}
```

这里以small bin的unlink举例：

<img src="D:\Desktop\PWN1\堆\堆溢出\Unlink.assets\image-20210327001414460.png" alt="image-20210327001414460" style="zoom:50%;" />

可以看出P最后的fd和bk指针并没有发生变化





## 堆释放

示例代码：

```c
#include <stdio.h>
#include <stdlib.h>
int main(){
    long *p1 = malloc(0x80);
    long *first_chunk = malloc(0x80);
    long *p2 = malloc(0x80);
    long *second_chunk = malloc(0x80);
    long *p3 = malloc(0x80);
    long *third_chunk = malloc(0x80);
    long *p4 = malloc(0x80);
    free(first_chunk);
    free(second_chunk);
    free(third_chunk);
    return 0;
}
```

由于申请的chunk为0x80所以不会进入fastbin（单项列表）而会进入unsortedbin（双向链表）

11行下断点

```
pwndbg> info locals 
p1 = 0x602010
first_chunk = 0x6020a0
p2 = 0x602130
second_chunk = 0x6021c0
p3 = 0x602250
third_chunk = 0x6022e0
p4 = 0x602370
```

14行后：

```
pwndbg> bin
fastbins
0x20: 0x0
0x30: 0x0
0x40: 0x0
0x50: 0x0
0x60: 0x0
0x70: 0x0
0x80: 0x0
unsortedbin
all: 0x6022d0 —▸ 0x6021b0 —▸ 0x602090 —▸ 0x7ffff7dd1b78 (main_arena+88) ◂— 0x6022d0
smallbins
empty
largebins
empty
```

看到有3个chunk进入了unsortedbin：

-   0x6022d0：third_chunk
-   0x6021b0：second_chunk
-   0x602090：first_chunk

first_chunk：

```
pwndbg> x/10gx 0x602090
0x602090:	0x0000000000000000	0x0000000000000091
0x6020a0:	0x00007ffff7dd1b78	0x00000000006021b0
0x6020b0:	0x0000000000000000	0x0000000000000000
0x6020c0:	0x0000000000000000	0x0000000000000000
0x6020d0:	0x0000000000000000	0x0000000000000000
```

second_chunk：

```
pwndbg> x/10gx 0x6021b0
0x6021b0:	0x0000000000000000	0x0000000000000091
0x6021c0:	0x0000000000602090	0x00000000006022d0
0x6021d0:	0x0000000000000000	0x0000000000000000
0x6021e0:	0x0000000000000000	0x0000000000000000
0x6021f0:	0x0000000000000000	0x0000000000000000
```

third_chunk：

```
pwndbg> x/10gx 0x6022d0
0x6022d0:	0x0000000000000000	0x0000000000000091
0x6022e0:	0x00000000006021b0	0x00007ffff7dd1b78
0x6022f0:	0x0000000000000000	0x0000000000000000
0x602300:	0x0000000000000000	0x0000000000000000
0x602310:	0x0000000000000000	0x0000000000000000
```





