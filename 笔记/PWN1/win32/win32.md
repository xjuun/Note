[TOC]

## 01_Win32课程介绍

## 02_字符编码

- ASCII
- GB2313或GB2312-80
- UNICODE：编码范围：0-0x10FFFF，可容纳100多万个符号
- Unicode的问题：Unicode只是一个符号集，他只规定了符号的而兼职代码，没有规定这个二进制代码该如何存储。
- 那么如何存储Unicode？UTF-16、UTF-8
  - UTF-16：
    - 以16位无符号整数位单位，不表示一个字符只有16位。
  - UTF-8

## 03_C语言中的宽字符



```
char szStr[] = "中国";
wchar_t swzStr[] = L"中国";
```

## 04_Win32 API中的宽字符

- 什么是win32 API？有哪些？在哪里？
  - 主要放在c:\windows\system32
  - 几个重要的dll：
    - kernel32.dll：最核心的功能模块，比如内存管理。进程和线程相关的函数等。
    - User32.dll：是Windows用户界面相关应用程序接口，如创建窗口和发送消息等。
    - GDI32.dll：全程：Graphical Device Interface(图形设备接口)，包含用于画图和显示文本的函数。

## 05_进程的创建过程

- 什么是进程？进程**提供**程序所需的资源，如数据、代码等。(使用是线程来做)

- 进程内存空间的地址划分：

  |     分区     |     x86 32位Windows     |
  | :----------: | :---------------------: |
  | 空指针赋值区 | 0x00000000 - 0x0000FFFF |
  |  用户模式区  | 0x00010000 - 0x7FFEFFFF |
  |  64KB禁入区  | 0x7FFF0000 - 0x7FFFFFFF |
  |     内核     | 0x80000000 - 0xFFFFFFFF |

- 进程的创建：

  - 使用函数：CreateProcess()
  - 进程的创建过程：
    1. 映射exe文件
    2. 创建内核对象EPROCESS
    3. 映射系统DLL
    4. 创建线程内核对象ETHREAD
    5. 系统启动线程
       - 映射DLL
       - 线程开始执行

## 06_创建进程



```C++
CreateProcessW(
    _In_opt_ LPCWSTR lpApplicationName,//对象名称
    _Inout_opt_ LPWSTR lpCommandLine,//命令行
    _In_opt_ LPSECURITY_ATTRIBUTES lpProcessAttributes,//如果该参数为空（NULL），那么句柄不能被继承。
    _In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,//这个参数决定的是线程是否被继承.
    _In_ BOOL bInheritHandles,//指示新进程是否从调用进程处继承了句柄。
    _In_ DWORD dwCreationFlags,//指定附加的、用来控制优先类和进程的创建的标志
    _In_opt_ LPVOID lpEnvironment,//指向一个新进程的环境块
    _In_opt_ LPCWSTR lpCurrentDirectory,//指向一个以NULL结尾的字符串，这个字符串用来指定子进程的工作路径
    _In_ LPSTARTUPINFOW lpStartupInfo,//指向一个用于决定新进程的主窗体如何显示的结构体
    _Out_ LPPROCESS_INFORMATION lpProcessInformation
    );
```



## 07_句柄表

- 什么是内核对象？

  像进程、线程、文件、互斥体、事件等在内核都有一个对应的结构体，这些结构体由内核负责管理，管这样的对象叫内核对象。

- 如何管理内核对象？

  每个进程都有一个句柄表。

## 08_进程相关API

```
TerminateProcess();
OpenProcess();
ResumeThread();
```



## 09_创建线程

- 什么是线程？
  1. 线程是附属在进程上的执行实体，是代码的执行流程
  2. 一个进程可以包含多个线程，但一个进程至少要包含一个线程。

```
CreateThread()
```

## 10_线程控制

完。