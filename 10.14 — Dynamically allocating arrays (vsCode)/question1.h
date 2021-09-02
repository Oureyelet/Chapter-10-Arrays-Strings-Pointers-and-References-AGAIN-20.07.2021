#include <iostream>

#ifndef QUEST_1
#define QUEST_1

int how_many()
{
    std::cout << "How many names you wish to enter: ";
    int x{};
    std::cin >> x;

    return x;
}

#endif // end QUEST_1