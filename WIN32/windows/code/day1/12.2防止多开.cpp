#include "windows.h"
#include <stdio.h>
int main(int argc, char *argv[])
{

    //创建令牌
    HANDLE g_mutex = CreateMutex(NULL, FALSE, "防止多开");

    DWORD DwRet = GetLastError();
    if (g_mutex)
    {
        if (DwRet == ERROR_ALREADY_EXISTS)
        {
            printf("该程序已经开启了，请勿再次开启！");
            CloseHandle(g_mutex);
            return 0;
        }
        else
        {
            WaitForSingleObject(g_mutex, INFINITE);
            for (int i = 0; i < 10; i++)
            {
                printf("%d----------\n", i);
                Sleep(500);
            }
            ReleaseMutex(g_mutex);
        }
    }
    else
    {
        printf("创建失败");
        CloseHandle(g_mutex);
        return 0;
    }
    return 0;
}
