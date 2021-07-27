#include <Windows.h>
#include <stdio.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    for (int i = 0; i < 20; i++)
    {
        Sleep(50);
        printf("%d-----------\n", i);
    }
    return 0;
}

int main()
{
    // 所要用到的函数：
    // GetThreadContext函数， SetThreadContext函数
    // 1.GetThreadContext函数用于获取线程上下文
    // BOOL GetThreadContext(
    //     HANDLE hThread,     // handle to thread with context 句柄
    //     LPCONTEXT lpContext // context structure 结构体
    // );
    //2.SetThreadContext函数：个设置修改线程上下文，可以先设置然后再获取
    // BOOL SetThreadContext(
    //     HANDLE hThread,           // handle to thread
    //     CONST CONTEXT * lpContext // context structure
    // );

    CONTEXT context;
    context.ContextFlags = CONTEXT_INTEGER;
    HANDLE hThread;
    hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    SuspendThread(hThread); //挂起线程

    context.Ecx = 0xDEADBEEF;
    SetThreadContext(hThread, &context);
    // 获取线程上下文：
    GetThreadContext(hThread, &context);
    printf("EAX: 0x%p\nECX: 0x%p\n", context.Eax, context.Ecx);

    ResumeThread(hThread);
    CloseHandle(hThread);
    return 0;
}