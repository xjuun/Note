#include <Windows.h>
#include <stdio.h>

int main()
{
    // CreateProcess 成功创建一个进程的时候，会返回四个数据：进程编号（ID），进程句柄，县城编号（ID），线程句柄
    // 进程ID 其实就是Windows任务管理器中的PID
    // 每个进程都有一张私有的句柄表。操作系统也有一张，是全局的句柄表，里面包含了所有正在运行的进程和线程
    //so，PID也就是线程ID是唯一的。

    // 要用到TerminateProcess函数
    // BOOL TerminateProcess(
    //     HANDLE hProcess, // handle to the process 句柄
    //     UINT uExitCode   // exit code for the process 退出代码
    // )

    TCHAR ChildProcessName[] = TEXT("C:\\Program Files\\Internet Explorer\\IEXPLORE.exe");
    TCHAR ChildProcessCmd[] = TEXT("http://www.baidu.com");

    STARTUPINFO si;         //（启动进程相关信息）
    PROCESS_INFORMATION pi; //（进程ID、线程ID、进程句柄、线程句柄）
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);

    if (CreateProcess(
            ChildProcessName,
            ChildProcessCmd,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi))
    {
        printf("PID:%x\n句柄:%x", pi.dwProcessId, pi.dwThreadId);
    }
    else
    {
        printf("Create Flase");
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}