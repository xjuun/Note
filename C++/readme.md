[TOC]



C++的学习，看到是编程达人的视频



# 2.this指针

1.  this指针是默认传入的，通常使用ecx
2.  成员函数都有this指针，无论是否使用
3.  this不能自增或自减
4.  this指针不占用结构体的宽度



# 3.构造函数与析构函数

构造函数：

-   不要返回值

-   构造函数的名字必须类名一样

-   可以构造有参函数，也可以无参函数。（称为重载）

-   编译器不要求必须提供 



析构函数：

-   只有一个，不能重载

-   不要返回值
-   不要参数
-   主要用于清理工作
-   编译器不要求必须提供

# 4.继承

-   继承就是数据的赋值
-   减少代码的编写
-   父类或基类
-   子类或派生类

如果重名：

```c++
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
```

继承不仅仅局限于父类，还可以找到父类的父类。

多重继承：

```c++
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
```

# 5.类成员的访问控制

```c++
// 类成员访问控制
 
struct sclass
{
private:
    int Bigger(int x, int y);

public:
    int x, y;
    int MAX(int x, int y);
};

```



-   当写struct时，默认所有成员都是public
-   当写class时，默认 所有成员都是private

