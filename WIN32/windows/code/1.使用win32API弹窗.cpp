#include <Windows.h>

int main()
{
    TCHAR strTitle[] = TEXT("���Ǳ���");
    TCHAR strContent[] = TEXT("��������");
    // �Ƽ�win�����ʹ��TEXT("")

    MessageBoxA(0, strContent, strTitle, MB_OK);
    // MessageBoxA()�Ĳ�������ʾ�ĺ��壺
    // int MessageBox(
    //     HWND hWnd,         // ���̾��
    //     LPCTSTR lpText,    // ��ʾ����
    //     LPCTSTR lpCaption, // ����
    //     UINT uType         // style
    // );

    return 0;
}