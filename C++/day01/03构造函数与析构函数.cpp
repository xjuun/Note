#include <iostream>

using namespace std;

struct Student
{
    int a, b, c, d;
    int sum = 1;
    // 构造函数的名字必须与名字一样
    // 不要返回值
    Student()
    {
        printf("构造函数1：无参数\n");
    }
    Student(int a, int b, int c, int d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        printf("构造函数2:有参数\n");
        sum = a;
    }
    ~Student()
    {
        printf("析构函数已执行%d\n", sum);
    }
};
Student student3(3, 4, 5, 6);
int main()
{
    Student student1;             //五参数的构造函数
    Student student2(2, 2, 3, 4); //有参数的构造函数
    return 0;
}