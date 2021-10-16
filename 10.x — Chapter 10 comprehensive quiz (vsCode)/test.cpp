#include <iostream>

int main()
{
    int i{ 1000000 };

    while ( i > 0 )
    {
        std::cout << i << '\n';
        i--;
    }


    return 0;
}