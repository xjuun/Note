#include <Windows.h>
#include <stdio.h>
int main()
{
    // GetModuleFileName 获得当前模块目录
    //GetCurrentDirectory 获得当前工作目录
    TCHAR strModule[256];
    TCHAR strCR[256];

    GetModuleFileName(NULL, strModule, 256);
    GetCurrentDirectory(256, strCR);
    printf("模块目录：%s\n工作目录: %s", strModule, strCR);
    return 0;
}

// 其他进程相关API:

// 获取当前进程ID（PID）：GetCurrentProcessId
// 获取当前进程句柄：GetCurrentProcess
// 获取命令行：GetCommandLine
// 获取启动信息：GetStartupInfo
// 遍历进程ID：EnumProcesses
// 快照：CreateToolhelp32Snapshot