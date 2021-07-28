#include <Windows.h>
#include <stdio.h>

int main()
{
    // 以挂起的形式创建进程，
    //CreateProcess函数的第六个参数dwCreationFlags，
    // 当创建进程的时候，会发现父进程和子进程在同一个cmd中
    // 如果想要取分的话就要借助第六个参数，写为 Create_NEW_CONSOLE
    // 如果是以挂起的方式创建进程，则使用CREATE_SUSPENDED
    TCHAR ChildProcessName[] = TEXT("C:/WINDOWS/system32/cmd.exe");
    TCHAR ChildProcessCmd[] = TEXT(" /c ping www.baidu.com");
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);
    if (CreateProcess(
            ChildProcessName,
            ChildProcessCmd,
            NULL,
            NULL,
            FALSE,
            CREATE_SUSPENDED,
            NULL,
            NULL,
            &si,
            &pi))
    {
        printf("CreateProcess Successfully!\n");
        for (int i = 0; i < 5; i++)
        {
            Sleep(1000);
            printf("%d---------------\n\n", i + 1);
        }
    }
    else
    {
        printf("CreateProcess ERROR %d\n", GetLastError());
    }
    // 上面的内容已经执行完了，
    // 恢复
    ResumeThread(pi.hThread);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    system("pause");

    return 0;
}