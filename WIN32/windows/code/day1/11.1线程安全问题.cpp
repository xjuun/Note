#include <windows.h>
#include <stdio.h>
#include <cstddef>
int countNumber = 10;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    while (countNumber > 0)
    {
        printf("Sell num: %d\n", countNumber);
        // 售出-1
        countNumber--;
        printf("Count: %d\n", countNumber);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    HANDLE hThread[2];
    hThread[0] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    hThread[1] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
    CloseHandle(hThread);

    return 0;
}