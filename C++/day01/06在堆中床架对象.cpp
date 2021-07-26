#include <iostream>
struct Person
{
public:
    int x, y;

    Person()
    {
        printf("构造函数!\n\n");
    }
    ~Person()
    {
        printf("析构函数\n\n");
    }
};
int main()
{
    // Person *p = new Person();
    // printf("其他\n\n");

    // delete p;

    int *q = (int *)malloc(sizeof(int) * 10);
    free(q);
    int *w = new int[10];
    delete[] w;

    Person *e = (Person *)malloc(sizeof(Person) * 10);
    free(e);
    Person *r = new Person[10];
    delete[] r;

    return 0;
}