#include <iostream>

int main()
{
    int a = 10;
    int *p = &a;
    int **q = &p;

    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Address of a: " << &a << std::endl;

    std::cout << "p: " << p << std::endl;
    std::cout << "Value of p: " << *p << std::endl;
    std::cout << "Address of p: " << &p << std::endl;

    std::cout << "q: " << q << std::endl;
    std::cout << "Value of q: " << *q << std::endl;
    std::cout << "Value of *q: " << **q << std::endl;

    return 0;
}