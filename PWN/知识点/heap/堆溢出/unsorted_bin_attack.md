[TOC]

# Tcache

tcache引入两个新的结构体，**tcache_entry**，**tcache_perthread_struct**。

## tcache_entry

```c
/* We overlay this structure on the user-data portion of a chunk when
   the chunk is stored in the per-thread cache.  */
typedef struct tcache_entry
{
  struct tcache_entry *next;
} tcache_entry;
```

用于链接空闲的chunk结构体，其中的next指向下一个大小相同的chunk。

这里的next指向的是user data，而fastbin的fd指向chunk开头的位置。

tcache_entry会复用空闲的chunk的user data部分。



## tcache_perthread_struct

```c
/* There is one of these for each thread, which contains the
   per-thread cache (hence "tcache_perthread_struct").  Keeping
   overall size low is mildly important.  Note that COUNTS and ENTRIES
   are redundant (we could have just counted the linked list each
   time), this is for performance reasons.  */
typedef struct tcache_perthread_struct
{
  char counts[TCACHE_MAX_BINS];
  tcache_entry *entries[TCACHE_MAX_BINS];
} tcache_perthread_struct;

# define TCACHE_MAX_BINS                64

static __thread tcache_perthread_struct *tcache = NULL;
```

每个 thread 都会维护一个 `tcache_perthread_struct`，它是整个 tcache 的管理结构，一共有 `TCACHE_MAX_BINS` 个计数器和 `TCACHE_MAX_BINS`项 tcache_entry，其中:

-   tcache_entry用单向链表的方式链接了相同大小的处于空闲状态（free后）的chunk
-   counts记录了tcache_entry链上空闲的chunk的数目，每条链上最多可以7个chunk。

