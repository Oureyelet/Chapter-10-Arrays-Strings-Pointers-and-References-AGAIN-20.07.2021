#include <iostream>

int main()
{
    std::cout << "Hello World\n";

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Introduction" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Pointers and arrays are intrinsically related in C++.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Array decay" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    In a previous lesson, you learned how to define a fixed array:
    */
    int array[]{9, 7, 5, 3, 1};// declare a fixed array of 5 integers
    
    /*
    To us, the above is an array of 5 integers, but to the compiler, array is a variable of type int[5]. 
    We know what the values of array[0], array[1], array[2], array[3], and array[4] are (9, 7, 5, 3, and 1 respectively).

    In all but two cases (which we’ll cover below), when a fixed array is used in an expression, the fixed array will decay 
    (be implicitly converted) into a pointer that points to the first element of the array. You can see this in the following 
    program:
    */
    // print address of the array's first element
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    // print the value of the pointer the array decays to
    std::cout << "The array decays to a pointer holding address: " << array << '\n';

    // Indirection through an array returns the first element (element 0)
    std::cout << *array << '\n';// print 9

    char name[]{ "John" };// C-style string (also an array)
    std::cout << *name << '\n';

    return 0;
}