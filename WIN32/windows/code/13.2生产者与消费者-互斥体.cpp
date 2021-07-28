#include <Windows.h>
#include <stdio.h>
// 互斥体下的生产者与消费者的代码
// 生产一次消费一次的有序进行，甚至还出现了先消费后生产的情
// 况，这个问题我们可以去修改代码解决，代码见13.3

HANDLE e_event;
int count = 10;
int container;
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{

    for (int i = 0; i < count; i++)
    {
        WaitForSingleObject(e_event, INFINITE);
        int threadID = GetCurrentThreadId();
        container = 1;

        printf("threadID:%d,  build:%d\n", threadID, container);
        ReleaseMutex(e_event);
    }

    return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
    for (int i = 0; i < count; i++)
    {
        WaitForSingleObject(e_event, INFINITE);
        int threadID = GetCurrentThreadId();
        container = 0;
        printf("threadID:%d,  consume:%d\n", threadID, container);
        ReleaseMutex(e_event);
    }

    return 0;
}
int main()
{

    e_event = CreateMutex(NULL, FALSE, NULL);

    HANDLE hThread[2];
    hThread[0] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    hThread[1] = CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);

    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    CloseHandle(e_event);

    return 0;
}