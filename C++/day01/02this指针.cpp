#include <iostream>
using namespace std;

struct Student
{
    int a;
    int b;
    int c;
    int sum;

    void Init(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        // this++ ：不能这么做

        sum = a + b + c;
    }
    void Print()
    {
        printf("SNM  is %d.\n", sum);
    }
};
int main()
{
    Student student;
    student.Init(1, 2, 3);
    student.Print();

    return 0;
}