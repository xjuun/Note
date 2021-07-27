#include <Windows.h>
#include <stdio.h>

int main()
{
    // 分别打开两便EXE，会发现只有当一个执行完之后另一个才会执行
    // 互斥体的创建：
    // HANDLE CreateMutex(
    //     LPSECURITY_ATTRIBUTES lpMutexAttributes, // SD 安全属性，包含安全描述符
    //     BOOL bInitialOwner,
    //     // initial owner 是否希望互斥体创建出来就有信号，
    //     // 或者说就可以使用，如果希望的话就为FALSE；
    //     // 官方解释为如果该值为TRUE则表示当前进程拥有该互斥体所有权
    //     LPCTSTR lpName // object name 互斥体的名字
    // );
    HANDLE cm = CreateMutex(NULL, FALSE, "XYZ");
    // 等待互斥体状态法伤变化，也就是有信号或为互斥体拥有者，获取令牌
    WaitForSingleObject(cm, INFINITE);
    for (int i = 0; i < 10; i++)
    {
        printf("%d----------\n", i);
        Sleep(500);
    }
    // 释放令牌
    ReleaseMutex(cm);
    return 0;
}