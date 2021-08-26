#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void print(int x)
{
    std::cout << "print(int): " << x << '\n';
}

void print(int* x)
{
    if(!x)
        std::cout << "print(int*): null\n";
    else
        std::cout << "print(int*): " << x << '\n';
}

void doSomething(std::nullptr_t x)
{
    std::cout << "in doSomething()\n";
}

#endif // end FUNCTIONS_H