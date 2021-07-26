#include <iostream>
struct Grandfather
{
    int age;
    char sex;
};

struct Father : Grandfather
{
    int age;
    int *wife;
};

int main()
{
    Father father;

    father.age = 12;
    father.Grandfather::age = 123;

    return 0;
}
//////////////////////////////////////////////////////////////
// 多重继承：
struct X
{
    int a;
    int b;
};
struct Y
{
    int c;
    int d;
};
struct Z : X, Y
{
    int e;
    int f;
};
//////////////////////////////////////////////////////////////
// 类成员访问控制

struct sclass
{
private:
    int Bigger(int x, int y);

public:
    int x, y;
    int MAX(int x, int y);
};
//////////////////////////////////////////////////////////////
class X
{
private:
    int x, y;
} class Y : public X
{
private:
    int q, w;
}