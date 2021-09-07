#include <iostream>

int main()
{
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Reference variables" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    So far, we’ve discussed two different kinds of variables:

    - Normal variables, which hold values directly.
    - Pointers, which hold the address of another value (or null) and their value can be retrieved through 
    indirection of address they point to.

    References are the third basic kind of variable that C++ supports. A reference is a C++ variable that acts as an alias to another object or value.

    C++ supports three kinds of references:

    1. References to non-const values (typically just called “references”, or “non-const references”), which we’ll 
    discuss in this lesson.
    2. References to const values (often called “const references”), which we’ll discuss in the next lesson.
    3. C++11 added r-value references, which we cover in detail in the chapter on move semantics.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "References to non-const values" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    A reference (to a non-const value) is declared by using an ampersand (&) between the reference type and the variable name:
    */
    int value{ 3 };// normal integer
    int &ref_value{ value };// reference to variable value


    /*
    In this context, the ampersand does not mean “address of”, it means “reference to”.

    References to non-const values are often just called “references” for short.

    Just like the position of the asterisk of pointers, it doesn’t matter if you place the ampersand at the type 
    or at the variable name.
    */
    int value_a{ 2 };
    // These two do the same.
    int& ref_value_a_1{ value_a };
    int &ref_value_a_2{ value_a };
    /*
    Best practice

    When declaring a reference variable, put the ampersand next to the type to make it easier to distinguish it from 
    the address-of operator. 
    */
    int& ref_value_a_3{ value }; //like this :)


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "References as aliases" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    
    */

    return 0;
}