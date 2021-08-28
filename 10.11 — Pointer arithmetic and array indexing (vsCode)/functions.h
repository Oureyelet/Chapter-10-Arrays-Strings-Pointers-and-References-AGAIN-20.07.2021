#include <iterator> // for std::size(), std::begin, std::end
#include <algorithm> // for std::count_it

#ifndef FUNC_H
#define FUNC_H

bool isVowel(char ch)
{
    switch(ch)
    {    case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
        case 'Y':
        case 'y':
            return true;
        default:
            return false;
    }
        
}

int* find(int* begin, int* end, int value)
{
   return std::count_if (begin, end, value);
}

#endif // and FUNC_H