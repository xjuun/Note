#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // 必须要调用一个默认的消息处理函数，关闭、最小化、最大化都是由默认消息处理函数处理的
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int APIENTRY wWinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPWSTR lpCmdLine,
                      int nCmdShow)
{
    //./MinGW/bin/ld -L MinGW\lib  -lmingw32 -lkernel32 -lmsvcrt -luser32 -lwow32 -lwldap32 -lwin32k -lvfw32 -lmingw32 -lmingwex -lwldap32 -ldxerr8 -ldxerr9 -lrpcdce4 -lbfd -liberty -L"./MinGW/lib/gcc/mingw32/3.4.5" -lgcc
    // HINSTANCE:模块的句柄，真正对象在0环，这个东西只是个索引
    // HINSTANCE hInstance，这是一个句柄，在Win32中H开头的通常都是句柄，这里的HINSTANCE是指向模块的句柄，实际上这个值就是模块在进程空间内的内存地址；
    // HINSTANCE hPrevInstance，该参数永远为空NULL，无需理解；
    // 第三、第四个参数（LPSTR lpCmdLine、int nCmdShow）是由CreateProcess的LPTSTR lpCommandLine、LPSTARTUPINFO lpStartupInfo参数传递的

    // 1.第一步：定义你的窗口是什么样的
    TCHAR szoutbuff[] = "";
    WNDCLASS wndclass = {0};
    TCHAR className[] = TEXT("My first window");
    // 设置背景颜色
    wndclass.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    // 设置窗口名字
    wndclass.lpszClassName = className;
    // 设置窗口地址
    wndclass.hInstance = hInstance;
    // 处理消息的窗口函数
    // 不是调用函数，只是告诉操作系统，当前窗口的回调函数是什么
    wndclass.lpfnWndProc = WindowProc;
    // 注册窗口类
    RegisterClass(&wndclass);

    // 2.第二步：创建并显示窗口
    HWND hwnd = CreateWindow(
        className,
        TEXT("我的第一个窗口"),
        WS_OVERLAPPEDWINDOW,
        10,
        10,
        600,
        300,
        NULL,
        NULL,
        hInstance,
        NULL);
    // 创建窗口
    ShowWindow(hwnd, SW_SHOW);
    // 3.第三步，接收消息并处理
    MSG msg;
    BOOL bret;
    while (bret = GetMessage(&msg, hwnd, 0, 0) != 0)
    {
        if (bret == -1)
        {
            sprintf(szoutbuff, "error:%d", GetLastError());
            OutputDebugString(szoutbuff);
        }
        else
        {
            // 转换消息
            TranslateMessage(&msg);
            // 分发消息
            DispatchMessage(&msg);
        }
    }

    return 0;
}
