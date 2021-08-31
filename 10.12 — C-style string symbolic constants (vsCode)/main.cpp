#include <iostream>

const char* hisName()
{
    return "Alex";
}

int main()
{
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "C-style string symbolic constants" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    In a previous lesson, we discussed how you could create and initialize a C-style string, like this:
    */
    char name[]{ "Alex" };
    std::cout << name << '\n';

    /*
    C++ also supports a way to create C-style string symbolic constants using pointers:
    */
    const char* myName{ "Mateusz" };// pointer to symbolic constant
    std::cout << myName << '\n';

    std::cout << hisName() << '\n';

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "std::cout and char pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    At this point, you may have noticed something interesting about the way std::cout handles pointers of different types.

    Consider the following example:
    */
    int iArray[]{1, 3, 5, 6, 7};
    char cArray[]{ "Alex" };
    const char* chArray{ "Alex" };

    std::cout << iArray << '\n';
    std::cout << cArray << '\n';
    std::cout << chArray << '\n';

    /*
    Why did the int array print an address, but the character arrays printed strings?

    The answer is that std::cout makes some assumptions about your intent. If you pass it a non-char pointer, it will 
    simply print the contents of that pointer (the address that the pointer is holding). However, if you pass it an object 
    of type char* or const char*, it will assume you’re intending to print a string. Consequently, instead of printing the 
    pointer’s value, it will print the string being pointed to instead!

    While this is great 99% of the time, it can lead to unexpected results. Consider the following case:
    */
    char c{ 'Q' };
    std::cout << &c << '\n';

    /*
    In this case, the programmer is intending to print the address of variable c. However, &c has type char*, 
    so std::cout tries to print this as a string! On the author’s machine, this printed:

    Qj`UUUU

    Why did it do this? Well, it assumed &c (which has type char*) was a string. So it printed the ‘Q’, and then kept going. 
    Next in memory was a bunch of garbage. Eventually, it ran into some memory holding a 0 value, which it interpreted as a 
    null terminator, so it stopped. What you see may be different depending on what’s in memory after variable c.

    This case is somewhat unlikely to occur in real-life (as you’re not likely to actually want to print memory addresses), 
    but it is illustrative of how things work under the hood, and how programs can inadvertently go off the rails.
    */

    







    return 0;
}