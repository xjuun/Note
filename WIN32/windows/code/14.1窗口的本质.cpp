#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

int main()
{
    // 我是在vscode中写的，编译的时候要加参数   -L MinGW\lib -lgdi32

    // 1.设备对象，画在哪里
    // NULL表示在桌面中绘画
    HWND hwnd = (HWND)NULL;
    // 2.获取设备对象上下文
    // HDC GetDC(
    //     HWND hWnd); //handle to window
    HDC hdc;
    hdc = GetDC(hwnd);
    // 3.创建画笔 设置线条的属性
    HPEN hpen;

    hpen = CreatePen(PS_SOLID, 10, RGB(0xFF, 00, 00));
    // 4.关联
    // HGDIOBJ SelectObject(
    //     HDC hdc,
    //     HGDIOBJ h); // handle to object
    SelectObject(hdc, hpen);

    // 5.开始画

    LineTo(hdc, 400, 400);

    // 6.释放资源

    DeleteObject(hpen);
    ReleaseDC(hwnd, hdc);

    return 0;
}