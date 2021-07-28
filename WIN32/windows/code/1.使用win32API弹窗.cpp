#include <Windows.h>

int main()
{
    TCHAR strTitle[] = TEXT("这是标题");
    TCHAR strContent[] = TEXT("这是内容");
    // 推荐win编程中使用TEXT("")

    MessageBoxA(0, strContent, strTitle, MB_OK);
    // MessageBoxA()的参数所表示的含义：
    // int MessageBox(
    //     HWND hWnd,         // 进程句柄
    //     LPCTSTR lpText,    // 显示内容
    //     LPCTSTR lpCaption, // 标题
    //     UINT uType         // style
    // );

    return 0;
}