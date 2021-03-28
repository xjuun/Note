[TOC]

## P1_Win API 开发简介

 

## P2_第一个win32



## P3_入口函数WinMain详解

```c++ 
int WINAPI WinMain(
    HINSTANCE hInstance,//应用程序当前实例的句柄
    HINSTANCE hPrevInstance,
    //应用程序的先前实例的句柄。同一个程序打开两次，出现两个窗口，第一次打开的窗口就是先前实例的窗口，对于一个32位程序，该参数总为NULL
    LPSTR lpCmdLine,//命令行的字符串的指针
    int nCmdShow//窗口显示方式，默认为SW_SHOWDEFAULT
)
```

## P4_Windows窗口程序简介

- 目前开发Windows窗口程序的主流技术：

  win32 API，MFC框架，QT框架，WPF 框架，Windows Forms

  <img src="C:\Users\86177\Desktop\PWN1\win32\img\2.png" alt="2" style="zoom:50%;" />

## P5_Windows第一个窗口程序开发

- 窗口类：WNDCLASS

  有三种：系统窗口类，应用程序全局窗口类，应用程序局部窗口类

  ```c++
  typedef struct tagWNDCLASSW {
      UINT        style;//窗口类的风格
      WNDPROC     lpfnWndProc;//窗口过程函数，处理窗口消息
      int         cbClsExtra;//指定窗口类结构之后要分配的额外字节数。系统将字节初始化为零
      int         cbWndExtra;//指定窗口实例之后要分配的额外字节数，系统将字节初始化为零
      HINSTANCE   hInstance;//窗口的实例句柄
      HICON       hIcon;//该窗口类所用的图标
      HCURSOR     hCursor;//该窗口类所用的光标
      HBRUSH      hbrBackground;//该窗口类多用的背景刷
      LPCWSTR     lpszMenuName;//该窗口类所用的菜单资源名称
      LPCWSTR     lpszClassName;//该窗口类名称
  }WNDCLASS;
  ```

  

## P6_Windows第一个窗口程序开发

```
注册窗口类：RegisterClass();
创建窗口：CreateWindow();
显示窗口：ShowWindow();
更新窗口：UpdateWindow()；

窗口过程：WNDPROC
默认窗口过程函数：DefWindowProc();
消息循环：GetMessage();
		MSG msg;
		while(GetMessage(&msg, NULL, 0, 0)){
			TranslateMessage(&msg); // 翻译消息
			DispatchMessage(&msg); // 分发消息
		}
```

```c++
#include<Windows.h>

// 自定义的窗口过程
LRESULT CALLBACK MyWindowProc(HWND hWnd, UINT Msg,
    WPARAM wParam, LPARAM lParam) {
    switch (Msg) {
    case WM_DESTROY:
        // 发送退出消息
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, Msg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nShowCmd) {
    // 1.注册窗口类
    WNDCLASSW wnd;
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0;

    // 背景画刷
    wnd.hbrBackground = (HBRUSH)(GetStockObject(BLACK_PEN));
    // 光标
    wnd.hCursor = LoadCursor(NULL, IDC_CROSS);
    // 图标
    wnd.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    // 默认窗口过程函数，用于处理消息
    wnd.lpfnWndProc = DefWindowProc;
    // 使用自定义窗口过程函数处理消息
    //wnd.lpfnWndProc = MyWindowProc;
    // 窗口类名
    wnd.lpszClassName = L"qwer";
    // 菜单资源名称
    wnd.lpszMenuName = NULL;
    // 窗口类样式
    wnd.style = CS_HREDRAW;
    // 实例句柄
    wnd.hInstance = hInstance;
    RegisterClass(&wnd);

    // 创建窗口（返回之前发送WM_CREATE的消息）
    HWND hWnd = CreateWindow(L"qwer", L"First windows",
        WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, NULL, NULL, hInstance, NULL);

    // 显示窗口
    ShowWindow(hWnd, nShowCmd);

    UpdateWindow(hWnd);

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); // 翻译消息
        DispatchMessage(&msg); // 分发消息
    }
}
```

## P7_WindowsAPI 常见数据类型

- 基本数据类型大写
- 指针类型的命令方式一般是在其指向的数据类型前加LP或P
- 各种句柄类型的命名方式一般都是在对象名前加H
- 无符号类型一把是以U开头



## P8_字符集SBCS,MBCS,UNICODE

## P9_Windows消息驱动机制

```
typedef struct tagMSG {
    HWND hwnd;//窗口句柄，表示消息所属的窗口
    UINT message;//消息的标识符，比如WM_KEYBORD
    WPARAM wParam;//消息的附加参数
    LPARAM lParam;//消息的附加参数
    DWORD time;//消息被传递时候的时间
    POINT pt;//消息被传递时候，光标在屏幕上的位置
} 
```

一个简单的消息循环包含调用一下三个API函数：

```
GetMessage();
TranslateMessage();
DispatchMessage();
```

## P10_线程和窗口的关系

- 消息队列是与线程（Thread）相关的，一个线程只能有一个消息队列与之对应。
- 在一个线程中可以产生多个窗口，所以每个窗口可共用一个线程消息队列，所有产生给某个窗口的消息，都先由创建这个窗口的线程处理；窗口在任何线程中都可以创建，但消息循环必须要和创建窗口在同一线程，否则窗口将无法从DispatchMessage()获取任何消息，为了使窗口接收这些消息，线程必须要有自己的消息循环。
- 

