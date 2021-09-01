#include <iostream>

int main()
{
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Dynamically allocating arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    In addition to dynamically allocating single values, we can also dynamically allocate arrays of variables. 
    Unlike a fixed array, where the array size must be fixed at compile time, dynamically allocating an array allows us to 
    choose an array length at runtime.

    To allocate an array dynamically, we use the array form of new and delete (often called new[] and delete[]):
    */
    std::cout << "Enter a positive integer: ";
    int lenght{};
    std::cin >> lenght;

    std::size_t* array{ new std::size_t[lenght]{} };// use array new.  Note that length does not need to be constant!

    std::cout << "I just allocated an array of integers of length " << lenght << '\n';

    array[0] = 5;// set element 0 to value 5

    delete[] array;// use array delete to deallocate array
    // we don't need to set array to nullptr/0 here because it's going to go out of scope immediately after this anyway


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Dynamically deleting arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////

    return 0;
}