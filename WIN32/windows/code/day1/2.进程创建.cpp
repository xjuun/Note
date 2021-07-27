#include <Windows.h>
#include <stdio.h>
int main()
{
    // BOOL CreateProcess(
    //     LPCTSTR lpApplicationName,                 // name of executable module 进程名（完整文件路径）
    //     LPTSTR lpCommandLine,                      // command line string 命令行传参
    //     LPSECURITY_ATTRIBUTES lpProcessAttributes, // SD 进程句柄
    //     LPSECURITY_ATTRIBUTES lpThreadAttributes,  // SD 线程句柄
    //     BOOL bInheritHandles,                      // handle inheritance option 句柄
    //     DWORD dwCreationFlags,                     // creation flags 标志
    //     LPVOID lpEnvironment,                      // new environment block 父进程环境变量
    //     LPCTSTR lpCurrentDirectory,                // current directory name 父进程目录作为当前目录，设置目录
    //     LPSTARTUPINFO lpStartupInfo,               // startup information 结构体详细信息（启动进程相关信息）
    //     LPPROCESS_INFORMATION lpProcessInformation // process information 结构体详细信息（进程ID、线程ID、进程句柄、线程句柄）
    // );

    //重要的就是前两个和后两个，
    // lpApplicationName 是进程名；
    // lpCommandLine 是命令行参数；
    // lpStartupInfo 是 STARTUPINFO 的一个结构体
    // lpProcessInformation 是 PROCESS_INFORMATION 的一个结构体

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
            0,
            NULL,
            NULL,
            &si,
            &pi))
    {
        printf("CreateProcess Successfully!\n");
    }
    else
    {
        printf("CreateProcess ERROR %d\n", GetLastError());
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    system("pause");

    return 0;
}