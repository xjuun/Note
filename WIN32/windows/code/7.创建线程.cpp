#include <Windows.h>
#include <stdio.h>
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    for (int i = 0; i < 10; i++)
    {
        Sleep(500);
        printf("%d------\n", i);
    }
    return 0;
}
int main()
{
    // HANDLE CreateThread(                          // 返回值是线程句柄
    //     LPSECURITY_ATTRIBUTES lpThreadAttributes, // SD 安全属性，包含安全描述符
    //     SIZE_T dwStackSize,                       // initial stack size 初始堆栈
    //     LPTHREAD_START_ROUTINE lpStartAddress,    // thread function 线程执行的函数代码
    //     LPVOID lpParameter,                       // thread argument 线程需要的参数
    //     DWORD dwCreationFlags,                    // creation option 标识，也可以以挂起形式创建线程
    //     [OUT]LPDWORD lpThreadId                   // thread identifier 返回当前线程ID
    // );

    HANDLE hThread;
    hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    CloseHandle(hThread);
    for (int i = 0; i < 10; i++)
    {
        Sleep(500);
        printf("%d------\n", i * 100);
    }
    return 0;
}