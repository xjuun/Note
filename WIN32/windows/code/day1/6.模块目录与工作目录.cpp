#include <Windows.h>
#include <stdio.h>
int main()
{
    // GetModuleFileName ��õ�ǰģ��Ŀ¼
    //GetCurrentDirectory ��õ�ǰ����Ŀ¼
    TCHAR strModule[256];
    TCHAR strCR[256];

    GetModuleFileName(NULL, strModule, 256);
    GetCurrentDirectory(256, strCR);
    printf("ģ��Ŀ¼��%s\n����Ŀ¼: %s", strModule, strCR);
    return 0;
}

// �����������API:

// ��ȡ��ǰ����ID��PID����GetCurrentProcessId
// ��ȡ��ǰ���̾����GetCurrentProcess
// ��ȡ�����У�GetCommandLine
// ��ȡ������Ϣ��GetStartupInfo
// ��������ID��EnumProcesses
// ���գ�CreateToolhelp32Snapshot