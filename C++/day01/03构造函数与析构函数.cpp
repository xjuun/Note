#include <iostream>

using namespace std;

struct Student
{
    int a, b, c, d;
    int sum = 1;
    // ���캯�������ֱ���������һ��
    // ��Ҫ����ֵ
    Student()
    {
        printf("���캯��1���޲���\n");
    }
    Student(int a, int b, int c, int d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        printf("���캯��2:�в���\n");
        sum = a;
    }
    ~Student()
    {
        printf("����������ִ��%d\n", sum);
    }
};
Student student3(3, 4, 5, 6);
int main()
{
    Student student1;             //������Ĺ��캯��
    Student student2(2, 2, 3, 4); //�в����Ĺ��캯��
    return 0;
}