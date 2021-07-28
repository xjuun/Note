#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#define CWA_EDIT 0x100
#define CWA_BUTTON_0 0x101
#define CWA_BUTTON_1 0x102
// 定义全局模块
HINSTANCE gHinstance;
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
    // 当窗口创建则开始创建子窗口控件
    case WM_CREATE:
    {
        // 创建编辑框
        CreateWindow(
            TEXT("EDIT"), //使用EDIT则为编辑框
            TEXT(""),     // 窗口名称
            // 前两个子窗口和可视必须设置，后两个是滚动条和自动换行
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE,
            0,               //在父窗口的起始x坐标
            0,               //在父窗口的起始y坐标
            400,             //控件宽度
            300,             //控件高度
            hwnd,            //父窗口句柄
            (HMENU)CWA_EDIT, //子窗口标识
            gHinstance,
            NULL); // 附加数据
      
        // 创建设置按钮
        CreateWindow(
            TEXT("BUTTON"), //使用按钮
            TEXT("设置"),   // 窗口名称
            // 个子窗口和可视
            WS_CHILD | WS_VISIBLE,
            450,                 //在父窗口的起始x坐标
            150,                 //在父窗口的起始y坐标
            80,                  //控件宽度
            20,                  //控件高度
            hwnd,                //父窗口句柄
            (HMENU)CWA_BUTTON_0, //子窗口标识
            gHinstance,
            NULL); // 附加数据

        CreateWindow(
            TEXT("BUTTON"), //使用按钮
            TEXT("获取"),   // 窗口名称
            // 个子窗口和可视
            WS_CHILD | WS_VISIBLE|MB_OK, 
            450,                 //在父窗口的起始x坐标
            200,                 //在父窗口的起始y坐标
            80,                  //控件宽度
            20,                  //控件高度
            hwnd,                //父窗口句柄
            (HMENU)CWA_BUTTON_1, //子窗口标识
            gHinstance,
            NULL); // 附加数据
        break;

    //    当点击按钮则处理
    case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
            case CWA_BUTTON_0:
            {
                SetDlgItemText(hwnd, (int)CWA_EDIT, TEXT("hack the world"));
                break;
            }
            case CWA_BUTTON_1:
            {
                TCHAR szEditBuff[0x80];
                GetDlgItemText(hwnd, (int)CWA_EDIT, szEditBuff, 0x80);
                MessageBox(NULL, szEditBuff, NULL, NULL);
                break;
            }
            }
            break;
        }
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
    WNDCLASS wndclass = { 0 };
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
    while (bret = GetMessage(&msg, NULL, 0, 0) != 0)
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
