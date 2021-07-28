#include <Windows.h>
#include <stdio.h>

HANDLE eventA;
HANDLE eventB;
int count = 10;
int container;
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{

    for (int i = 0; i < count; i++)
    {
        // 修改A的信号，等待
        WaitForSingleObject(eventA, INFINITE);
        // 获取当前线程ID
        int threadID = GetCurrentThreadId();

        container = 1;

        printf("threadID:%d,  build:%d\n", threadID, container);
        // 给eventB信号
        SetEvent(eventB);
    }

    return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
    for (int i = 0; i < count; i++)
    {
        // 修改B的信号，等待
        WaitForSingleObject(eventB, INFINITE);
        int threadID = GetCurrentThreadId();
        container = 0;
        printf("threadID:%d,  consume:%d\n", threadID, container);
        // 给eventA信号
        SetEvent(eventA);
    }

    return 0;
}
int main()
{
    // 创建事件
    // 线程的前提是互斥
    // 顺序按照先生产后消费,所以事件A设置信号,事件B需要通过生产者线程来设置信号
    eventA = CreateEvent(NULL, FALSE, TRUE, NULL);
    eventB = CreateEvent(NULL, FALSE, FALSE, NULL);
    HANDLE hThread[2];
    hThread[0] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    hThread[1] = CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);

    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    CloseHandle(eventA);
    CloseHandle(eventB);
    return 0;
}