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
DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{
    for (int i = 0; i < 20; i++)
    {
        Sleep(50);
        printf("%d-----------\n", i);
        if (i == 19)
            return 1;
    }
    return 0;
}

int main()
{
    // 介绍三个函数：
    // WaitForSingleObject，WaitForMultipleObjects，GetExitCodeThread
    // ////////////////////////////////////////////////////////////////////
    // 1.WaitForSingleObject函数
    // DWORD WaitForSingleObject(
    //     HANDLE hHandle,      // handle to object 句柄
    //     DWORD dwMilliseconds // time-out interval 等待超时时间（毫秒）
    //     如果你想一直等待的话，可以将第二参数的值设置为INFINITE。
    // );

    // HANDLE hThread;
    // hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    // WaitForSingleObject(hThread, INFINITE);
    // printf("OK\n");
    // CloseHandle(hThread);
    // /////////////////////////////////////////////////////////////////////
    // 2.WaitForMultipleObjects函数：它可以等待多个内核对象的状态发生变更
    // DWORD WaitForMultipleObjects(
    //     DWORD nCount,             // number of handles in array 内核对象的数量
    //     CONST HANDLE * lpHandles, // object-handle array 内核对象的句柄数组
    //     BOOL bWaitAll,            // wait option 等待模式
    //     DWORD dwMilliseconds      // time-out interval 等待超时时间（毫秒）
    // );
    // HANDLE hThread[2];
    // hThread[0] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    // hThread[1] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    // WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
    // printf("OK\n");
    // CloseHandle(hThread[0]);
    // CloseHandle(hThread[1]);
    // /////////////////////////////////////////////////////////////////////
    // 3.GetExitCodeThread函数
    // 线程函数会有一个返回值（DWORD），这个返回值可以根据你的需求进行返回，而我们需要如何获取这个返
    // 回结果呢？这时候就可以使用GetExitCodeThread函数 return 0;
    // BOOL GetExitCodeThread(
    //     HANDLE hThread,    // handle to the thread
    //     LPDWORD lpExitCode // termination status
    // );
    // HANDLE hThread[2];
    // DWORD dwresult1, dwresult2;
    // hThread[0] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    // hThread[1] = CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
    // WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
    // GetExitCodeThread(hThread[0], &dwresult1);
    // GetExitCodeThread(hThread[1], &dwresult2);
    // printf("1:%d\n2:%d\nOK\n", dwresult1, dwresult2);
    // CloseHandle(hThread[0]);
    // CloseHandle(hThread[1]);
    return 0;
}