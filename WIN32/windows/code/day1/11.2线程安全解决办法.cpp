#include <Windows.h>
#include <stdio.h>
CRITICAL_SECTION cs; //创建全局变量
int countNumber = 10;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    EnterCriticalSection(&cs); // 构建临界区，获取令牌
    while (countNumber > 0)
    {

        printf("Sell num: %d\n", countNumber);
        countNumber--;
        printf("Count: %d\n", countNumber);
    }
    LeaveCriticalSection(&cs); // 离开临临界区，归还令牌

    return 0;
}

int main()
{
    InitializeCriticalSection(&cs); //使用之前进行初始化
    HANDLE hThread[2];
    hThread[0] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    hThread[1] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    return 0;
}