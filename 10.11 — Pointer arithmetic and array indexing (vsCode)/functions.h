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
            return true;
        default:
            return false;
    }
        
}

#endif // and FUNC_H