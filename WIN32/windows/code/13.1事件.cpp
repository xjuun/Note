#include <Windows.h>
#include <stdio.h>
HANDLE e_event;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    WaitForSingleObject(e_event, INFINITE);
    printf("ThreadProc - running...\n");
    getchar();
    return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
    WaitForSingleObject(e_event, INFINITE);
    printf("ThreadProc2 - running...\n");
    getchar();
    return 0;
}

int main()
{
    // 创建事件
    // HANDLE CreateEvent(
    //     LPSECURITY_ATTRIBUTES lpEventAttributes, // SD 安全属性，包含安全描述符
    //     BOOL bManualReset,
    //     // reset type 如果你希望当前事件类型是通知类型则写TRUE，反之FALSE
    //     BOOL bInitialState,
    //     // initial state 初始状态，决定创建出来时候是否有信号，有为TRUE，没有为FALSE
    //     LPCTSTR lpName // object name 事件名字
    // );

    // 第二个参数，FALSE表示费通知类型，也就是互斥；TRUE表示为通知类型
    // 第三个参数表示初始状态没有信号。
    e_event = CreateEvent(NULL, TRUE, FALSE, NULL);

    HANDLE hThread[2];
    hThread[0] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    hThread[1] = CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);

    // 设置事件为已通知，也就是设置为有信号
    SetEvent(e_event);

    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    CloseHandle(e_event);

    return 0;
}