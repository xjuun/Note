#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 第三个参数是虚拟键码（键盘上每个键都对应一个虚拟键码）
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    // 处理窗口关闭
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    // 当键盘按下处理
    case WM_KEYDOWN:
    {

        char szoutbuff[0x80] = "";
        sprintf_s(szoutbuff, "error:%d", GetLastError());
        OutputDebugString((LPCWSTR)szoutbuff);
    }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int APIENTRY wWinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPWSTR lpCmdLine,
                      int nCmdShow)
{

    char szoutbuff[0x80] = "";
    WNDCLASS wndclass = {0};
    TCHAR className[] = TEXT("My first window");
    wndclass.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    wndclass.lpszClassName = className;
    wndclass.hInstance = hInstance;
    wndclass.lpfnWndProc = WindowProc;
    RegisterClass(&wndclass);
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
    ShowWindow(hwnd, SW_SHOW);
    MSG msg;
    BOOL bret;
    while (bret = GetMessage(&msg, hwnd, 0, 0) != 0)
    {
        if (bret == -1)
        {
            sprintf_s(szoutbuff, "error:%d", GetLastError());
            OutputDebugString((LPCWSTR)szoutbuff);
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return 0;
}
