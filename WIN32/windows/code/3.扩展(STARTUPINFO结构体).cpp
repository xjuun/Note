#include <Windows.h>
#include <stdio.h>
int main()
{
    // 创建进程CreateProcess函数倒数第二个参数是一个STARTUPINFO结构体
    // typedef struct _STARTUPINFOA
    // {
    //     DWORD cb;
    //     LPSTR lpReserved;
    //     LPSTR lpDesktop;
    //     LPSTR lpTitle;
    //     DWORD dwX;
    //     DWORD dwY;
    //     DWORD dwXSize;
    //     DWORD dwYSize;
    //     DWORD dwXCountChars;
    //     DWORD dwYCountChars;
    //     DWORD dwFillAttribute;
    //     DWORD dwFlags;
    //     WORD wShowWindow;
    //     WORD cbReserved2;
    //     LPBYTE lpReserved2;
    //     HANDLE hStdInput;
    //     HANDLE hStdOutput;
    //     HANDLE hStdError;
    // } STARTUPINFOA, *LPSTARTUPINFOA;
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));

    si.cb = sizeof(si);
    GetStartupInfo(&si);
    printf("%d %d %d %d %d %d %d %d\n", si.dwX, si.dwY, si.dwXSize, si.dwYSize, si.dwXCountChars,
           si.dwYCountChars, si.dwFillAttribute, si.dwFlags);

    // 以上代码直接打开与在DTDbug中调试打开时不一样的。
    return 0;
}