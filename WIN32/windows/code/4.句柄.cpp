#include <Windows.h>
#include <stdio.h>

int main()
{
    // CreateProcess �ɹ�����һ�����̵�ʱ�򣬻᷵���ĸ����ݣ����̱�ţ�ID�������̾�����سǱ�ţ�ID�����߳̾��
    // ����ID ��ʵ����Windows����������е�PID
    // ÿ�����̶���һ��˽�еľ��������ϵͳҲ��һ�ţ���ȫ�ֵľ������������������������еĽ��̺��߳�
    //so��PIDҲ�����߳�ID��Ψһ�ġ�

    // Ҫ�õ�TerminateProcess����
    // BOOL TerminateProcess(
    //     HANDLE hProcess, // handle to the process ���
    //     UINT uExitCode   // exit code for the process �˳�����
    // )

    TCHAR ChildProcessName[] = TEXT("C:\\Program Files\\Internet Explorer\\IEXPLORE.exe");
    TCHAR ChildProcessCmd[] = TEXT("http://www.baidu.com");

    STARTUPINFO si;         //���������������Ϣ��
    PROCESS_INFORMATION pi; //������ID���߳�ID�����̾�����߳̾����
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
        printf("PID:%x\n���:%x", pi.dwProcessId, pi.dwThreadId);
    }
    else
    {
        printf("Create Flase");
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}