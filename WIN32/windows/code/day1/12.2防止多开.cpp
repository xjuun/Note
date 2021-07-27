#include "windows.h"
#include <stdio.h>
int main(int argc, char *argv[])
{

    //��������
    HANDLE g_mutex = CreateMutex(NULL, FALSE, "��ֹ�࿪");

    DWORD DwRet = GetLastError();
    if (g_mutex)
    {
        if (DwRet == ERROR_ALREADY_EXISTS)
        {
            printf("�ó����Ѿ������ˣ������ٴο�����");
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
        printf("����ʧ��");
        CloseHandle(g_mutex);
        return 0;
    }
    return 0;
}
