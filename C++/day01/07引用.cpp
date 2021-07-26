#include <iostream>

class Base
{
public:
    int x;
};
int main()
{
    // int x = 10;
    // int &y = x;
    // y = 20;
    // printf("%d", x);
    Base b;
    b.x = 1;

    Base &base = b;
    base.x = 2;
    printf("%d", b.x);
    return 0;
}