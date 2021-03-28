# Ret2text

首先file和checksec一下：

![1](1.png)

ida打开：

![2](2.png)

观察到有个vulnerable()函数：

![3](3.png)

还有个后门函数：get_shell()

![4](4.png)

gdb打开，main处下断点后跟进，输入12345678后查看stack：

![5](5.png)

此时ebp= 0xffffd108,

![8](8.png)

将黄色与红色全部覆盖后填入get_shell()的地址。

exp如下：

![6](6.png)

getshell：

![7](7.png)

