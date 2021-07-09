[TOC]





# 第一章 背景知识

## 1.3 基础知识

### 1.3.1  80x86处理器的工作模式

```
三种工作模式：
实模式、保护模式、虚拟86模式
```

![image-20210702212544707](readme/image-20210702212544707.png)

![image-20210702213119740](readme/image-20210702213119740.png)

![image-20210702212714948](readme/image-20210702212714948.png)



### 1.3.2 Windows的内存管理



# 第二章 准备环境

![image-20210702223207339](readme/image-20210702223207339.png)

就是masm安装和bat之类的。

```sh
@echo off
rem 请根据 Masm32 软件包的安装目录修改下面的 Masm32Dir 环境变量！
set Masm32Dir=C:\Masm32
set include=%Masm32Dir%\Include;%include%
set lib=%Masm32Dir%\lib;%lib%
set path=%Masm32Dir%\Bin;%Masm32Dir%;%PATH%
set Masm32Dir=
echo on
```



# 第三章 使用NASM

## 3.1 win32汇编源程序的结构

win32版hello world：

```assembly
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 使用 nmake 或下列命令进行编译和链接:
; ml /c /coff Test.asm
; rc Test.rc
; Link /subsystem:windows Test.obj Test.res
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		.386
		.model flat,stdcall
		option casemap:none
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; Include 文件定义
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
include		windows.inc
include		user32.inc
includelib	user32.lib
include		kernel32.inc
includelib	kernel32.lib
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 数据段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		.const

szCaption	db	'恭喜',0
szText		db	'当您看到这个信息的时候，您已经可以编译Win32汇编程序了!',0

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 代码段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		.code
start:
		invoke	MessageBox,NULL,offset szText,offset szCaption,MB_OK
		invoke	ExitProcess,NULL
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		end	start
```

makefile中的内容：

```makefile
EXE = Test.exe		#指定输出文件
OBJS = Test.obj		#需要的目标文件
LINK_FLAG = /subsystem:windows	#连接选项
ML_FLAG = /c /coff		#编译选项
$(EXE): $(OBJS) $(RES)
	Link $(LINK_FLAG) $(OBJS) $(RES)
.asm.obj:
	ml $(ML_FLAG) $<
.rc.res:
	rc $<
clean:
	del *.obj
	del *.res
```

### 3.1.1 模式定义

```assembly
.386
.model flat,stdcall
option casemap:none
```

这些指令定义了程序使用的指令集、工作模式和格式

1.  指令使用的指令集

    .386 语句是汇编语言的伪指令。

    类似的还有.8086， .186等等等。

2.  .model 语句

    用来定于程序工作的工作模式，使用方法：

    ```assembly
    .model 内存模式[,语言模式] [其他模式]
    ```

    ![image-20210709131112465](readme/image-20210709131112465.png)

3.  option语句

    这个语句定义了程序中的变量和子程序名是否对大小写敏感，Win32中的API大小写敏感，所以必须写



### 3.1.2 段的定义

1.  段的概念

    .stack  .data  .data? .code 等都是分段的伪指令，win32中实际上只有代码和数据之分，win32汇编不用考虑堆栈所以

    .stack的定义通常被忽略。

2.  数据段

    可读可写的已定义变量，可读可写的未定义变量，常量。

    比如要用一个100kb的缓冲区，可以：

    ```assembly
    szBuffer	db	100 * 1024 dup(?)
    ```

    

### 3.1.3 程序结束和程序入口

```assembly
end [开始地址]

比如：
end start
```

### 3.1.4 注释和换行

注释使用分号

换行使用反斜杠

## 3.2 调用API

int 21h是DOS中断

int 13h和int 10h是BIOS中的磁盘中昂段和视频中断

![image-20210709173915496](readme/image-20210709173915496.png)

```c
int MessageBox(
	HWND hWnd,
    LPCTSTR lptext,
    LPCTSTR lpcaption,
    UINT utype
);
```

使用汇编就是：

```asm
push utype
push lpcaption
push lptext
push hwnd
call MessageBox
```

1.  使用invoke语句

    ```asm
    invoke 函数名[,参数1] [，参数2]...
    例如
    invoke MessageBox,NULL,offset szText,offset,szcaption,MB_OK
    ```

2.  API函数的返回值

    如果返回值eax可以容纳，就放入eax中；

    若不能容纳，则返回指针，eax。

3.  include语句

4.  includelib语句

### 3.2.3 API参数中的等值定义

![image-20210709174805244](readme/image-20210709174805244.png)



## 3.3 标号、变量和数据结构

![image-20210709203558608](readme/image-20210709203558608.png)

### 3.3.1 标号

1.  标号的定义

当在程序中使用一条跳转指令的时候，可以用标号来表示跳转的目的地，编译器在编
译的时候会把它替换成地址，标号既可以定义在目的指令同--行的头部，也可以在目的指
令前一行单独用一行定义，标号定义的格式是:

>   标号名：	目的指令	;方法1
>
>   或者
>
>   标号名：：	目的指令	;方法2

常用的方式是方法1（一个冒号）；当需要从一个子程序调到另外一个子程序中的标号时，可以使用方法2.

2.  MASM中的@@

![image-20210709204049486](readme/image-20210709204049486.png)

### 3.3.2 全局变量

1.  全局变量的定义

    格式

    >   变量名		类型		初始值1，初始值2......
    >
    >   变量名		类型		重复数量 dup (初始值1，初始值2,..........)

变量类型见下表：

![image-20210709204307792](readme/image-20210709204307792.png)

几个例子：

```assembly
.data
wHour		dw	?	;定义了一个未初始化的word变量名称为wHour
wMinute		dw	10	;定义了一个word类型的变量，wMinute=10
_hWnd		dd	?	;
word_Buffer	dw	100 dup (1,2)
;定义了一组数字，以0001,0002,0001,0002...的顺序重复100遍，共200个字
szBuffer	byte	1024 dup (?);定义了1024字节大小的缓冲区
sztext		db		'hello world';定义字符串
```



