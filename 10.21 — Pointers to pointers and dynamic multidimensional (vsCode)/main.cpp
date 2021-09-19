#include <iostream>

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointers to pointers and dynamic multidimensional" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    This lesson is optional, for advanced readers who want to learn more about C++. No future lessons build on this lesson.
    A pointer to a pointer is exactly what you’d expect: a pointer that holds the address of another pointer.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointers to pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    A normal pointer to an int is declared using a single asterisk:
    */
    int* ptr{ nullptr }; // pointer to an int, one asterisk

    /*
    A pointer to a pointer to an int is declared using two asterisks:
    */
    int** ptr_ptr{ nullptr };// pointer to a pointer to an int, two asterisks
    
    /*
    A pointer to a pointer works just like a normal pointer — you can perform indirection through it to retrieve the value 
    pointed to. And because that value is itself a pointer, you can perform indirection through it again to get to the 
    underlying value. These indirections can be done consecutively:
    */
    int value{ 5 };

    int* ptr_value{ &value };
    std::cout << *ptr_value << '\n';// Indirection through pointer to int to get int value

    int** ptr_ptr_value{ &ptr_value };
    std::cout << **ptr_ptr_value << '\n';// first indirection to get pointer to int, second indirection to get int value

    /*
    Note that you can not set a pointer to a pointer directly to a value:

    int value{ 5 };
    int** ptr_ptr_value{ &&value };// not valid
    */

    /*
    This is because the address of operator (operator&) requires an lvalue, but &value is an rvalue.

    However, a pointer to a pointer can be set to null:
    */
    int*** ptr_ptr_ptr_value{ nullptr };


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Arrays of pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Pointers to pointers have a few uses. The most common use is to dynamically allocate an array of pointers:
    */
    int** array{ new int*[10] };// allocate an array of 10 int pointers
    /*
    This works just like a standard dynamically allocated array, except the array elements are of type 
    “pointer to integer” instead of integer.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Two-dimensional dynamically allocated arrays" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Another common use for pointers to pointers is to facilitate dynamically allocated multidimensional arrays 
    (see 10.5 -- Multidimensional Arrays for a review of multidimensional arrays).

    Unlike a two dimensional fixed array, which can easily be declared like this:
    */
    int array[5][10];

    //There are two possible solutions here. If the rightmost array dimension is a compile-time constant, you can do this:
    int (*array)[5]{ new int[10][5] };
    /*
    The parenthesis are required here to ensure proper precedence. In C++11 or newer, this is a good place to use automatic 
    type deduction:
    */
    auto array_g{ new int[10][5] };// so much simpler!

    /*
    Unfortunately, this relatively simple solution doesn’t work if any non-leftmost array dimension isn’t 
    a compile-time constant. In that case, we have to get a little more complicated. First, we allocate an array of 
    pointers (as per above). Then we iterate through the array of pointers and allocate a dynamic array for each array element. 
    Our dynamic two-dimensional array is a dynamic one-dimensional array of dynamic one-dimensional arrays!
    */

    //... for more about Pointers to pointers and dynamic multidimensional go see: https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/




    return 0;
}