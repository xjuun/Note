

[TOC]



## 2.2操作系统内存分配的相关函数

-   对heap的操作：
    -   操作系统提供brk()函数
    -   c运行是库提供sbrk()函数
-   对mmap营社区的操作：
    -   操作系统提供mmap和munmap函数

### 2.2.1heap操作相关函数

brk()为系统调用，sbrk()为 C 库函数

# 3.概述

### 3.1.1内存管理的方法

1.  c风格的内存管理程序

    主要通过malloc()和free()函数

    内存管理程序主要通过调用brk()或者mmap()进程添加额外的虚拟内存。

2.  池式内存管理

3.  引用计数

4.  垃圾收集



## 3.2ptmalloc内存管理概述

### 3.2.1 简介

ptmalloc 实现了 malloc()，free()以及一组其它的函数. 以提供动态内存管理的支持。分 配器处在用户程序和内核之间，它响应用户的分配请求，向操作系统申请内存，然后将其返 回给用户程序，

### 3.2.3 内存管理数据结构概述

#### 3.2.3.1 Main_arena与non_main_arena

主分配区（main arena），非主分配区（non main arena）.

主分配 区可以访问进程的 heap 区域和 mmap 映射区域，也就是说主分配区可以使用 sbrk 和 mmap 向操作系统申请虚拟内存。而非主分配区只能访问进程的 mmap 映射区域，非主分配区每 次使用 mmap()向操作系统“批发”HEAP_MAX_SIZE（32 位系统上默认为 1MB，64 位系统默 认为 64MB）大小的虚拟内存。

#### 3.2.3.2 chunk

amp中：

-   M表示前一个快是否在使用中，p为0表示前一个chunk为空闲，这时prev_size有效，可以通过prev_size来寻找。

-   M表示当前chunk是从哪个内存区获得的虚拟内存，为1表示从mmap映射区分配的，否则是从heap区域分配的。
-   A表示该chunk是否属于主分配区或者非主分配区，如 果属于非主分配区，将该位置为 1，否则置为 0。

#### 3.2.3.3 空闲 chunk 容器

1.  **Bins**

    用户free掉的内存不会马上给系统。

    ptmalloc 将相似大小的 chunk 用双向链表链接起来，这样的一个链表被称为一个 bin。Ptmalloc 一共 维护了 128 个 bin，并使用一个数组来存储这些 bin（如下图所示）。

![image-20210620161448544](readme/image-20210620161448544.png)

​	数组中的第一个是unsorted bin；之后的64个bin是small bin，同一个small bin大小相同，相邻的small bin中的chunk大小相差8bytes。

​	small bins 中的 chunk 按照最近使用顺序进行排列（FIFO），最后释放的 chunk 被链接到链表的头部， 而申请 chunk 是从链表尾部开始

​	large bins 中的每一个 bin 分别包含了一个给定范围 内的 chunk，其中的 chunk 按大小序排列。相同大小的 chunk 同样按照最近使用顺序排列。

​	当空闲的 chunk 被链接到 bin 中的时候，ptmalloc 会把表示该 chunk 是否处于使用中的 标志 P 设为 0（注意，这个标志实际上处在下一个 chunk 中），同时 ptmalloc 还会检查它前 后的 chunk 是否也是空闲的，如果是的话，ptmalloc 会首先把它们合并为一个大的 chunk， 然后将合并后的 chunk 放到 unstored bin 中。要注意的是，并不是所有的 chunk 被释放后就 立即被放到 bin 中。ptmalloc 为了提高分配的速度，会把一些小的的 chunk 先放到一个叫做 fast bins 的容器内。

2.  **Fast bin**

​	fast bins 中的 chunk 并不改变它的使用标志 P，这样也就无法将它们合并。

​	在某个特定的时候，ptmalloc会遍历fast bins中的chunk，将相邻的空闲 chunk 进行合并，并将合并后的 chunk 加入 unsorted bin 中，然后再将 usorted bin 里的 chunk 加入 bins 中。

3.  **unsorted bin**

​	unsorted bin 的队列使用 bins 数组的第一个，如果被用户释放的 chunk 大于 max_fast， 或者 fast bins 中的空闲 chunk 合并后，这些 chunk 首先会被放到 unsorted bin 队列中，在进 行 malloc 操作的时候，如果在 fast bins 中没有找到合适的 chunk，则 ptmalloc 会先在 unsorted bin 中查找合适的空闲 chunk，然后才查找 bins。

​	如果 unsorted bin 不能满足分配要求。malloc 便会将 unsorted bin 中的 chunk 加入 bins 中。然后再从 bins 中继续进行查找和分配过程。从 这个过程可以看出来，unsorted bin 可以看做是 bins 的一个缓冲区，增加它只是为了加快分 配的速度。

4.   TOPchunk

​    并不是所有的 chunk 都按照上面的方式来组织，实际上，有三种例外情况。Top chunk， mmaped chunk 和 last remainder。

5.   mmaped chunk

​    当需要分配的 chunk 足够大，而且 fast bins 和 bins 都不能满足要求，甚至 top chunk 本 身也不能满足分配需求时，ptmalloc 会使用 mmap 来直接使用内存映射来将页映射到进程空间。

6.  Last remainder

​    Last remainder 是另外一种特殊的 chunk，就像 top chunk 和 mmaped chunk 一样，不会 在任何 bins 中找到这种 chunk。当需要分配一个 small chunk，但在 small bins 中找不到合适 的 chunk，如果 last remainder chunk 的大小大于所需的 small chunk 大小，last remainder chunk 被分裂成两个 chunk，其中一个 chunk 返回给用户，另一个 chunk 变成新的 last remainder chuk。

#### 3.2.3.4 sbrk与mmap

​    .bss 段之上的这块分配给用户程序的空间被称为 heap。 

​     start_brk 指向 heap 的开始，而 brk 指向 heap 的顶部。







