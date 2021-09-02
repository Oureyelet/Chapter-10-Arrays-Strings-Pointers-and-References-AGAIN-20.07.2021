#include <iostream>
#include "question1.h"
#include <string>
#include <limits>//for: std::cin.ignore
#include <iomanip> // for ws
#include <utility> // for swap
#include <algorithm> // for sort


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
    /*
    When deleting a dynamically allocated array, we have to use the array version of delete, which is delete[].

    This tells the CPU that it needs to clean up multiple variables instead of a single variable. One of the most common 
    mistakes that new programmers make when dealing with dynamic memory allocation is to use delete instead of delete[] 
    when deleting a dynamically allocated array. Using the scalar version of delete on an array will result in undefined 
    behavior, such as data corruption, memory leaks, crashes, or other problems.

    One often asked question of array delete[] is, “How does array delete know how much memory to delete?” The answer is 
    that array new[] keeps track of how much memory was allocated to a variable, so that array delete[] can delete the 
    proper amount. Unfortunately, this size/length isn’t accessible to the programmer.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Dynamic arrays are almost identical to fixed arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    In lesson 10.10 -- Pointers and arrays, you learned that a fixed array holds the memory address of the first array element. 
    You also learned that a fixed array can decay into a pointer that points to the first element of the array. In this decayed 
    form, the length of the fixed array is not available (and therefore neither is the size of the array via sizeof()), but 
    otherwise there is little difference.

    A dynamic array starts its life as a pointer that points to the first element of the array. Consequently, it has the same 
    limitations in that it doesn’t know its length or size. A dynamic array functions identically to a decayed fixed array, 
    with the exception that the programmer is responsible for deallocating the dynamic array via the delete[] keyword.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing dynamically allocated arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    
    //If you want to initialize a dynamically allocated array to 0, the syntax is quite simple:
    int* our_array_77{ new int[lenght]{} };

    /*
    Prior to C++11, there was no easy way to initialize a dynamic array to a non-zero value (initializer lists only 
    worked for fixed arrays). This means you had to loop through the array and assign element values explicitly.
    */
    int* array_77 = new int[5];
    array_77[0] = 9;
    array_77[1] = 7;
    array_77[2] = 4;
    array_77[3] = 3; 
    array_77[4] = 2;

    /*
    Super annoying!

    However, starting with C++11, it’s now possible to initialize dynamic arrays using initializer lists!
    */
    int fixedArray[]{ 9, 7, 5, 3, 1  };// initialize a fixed array before C++11
    int* next_array{ new int[5]{ 9, 7, 5, 3, 1 } };// initialize a dynamic array since C++11    


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Resizing arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Dynamically allocating an array allows you to set the array length at the time of allocation. However, C++ does not 
    provide a built-in way to resize an array that has already been allocated. It is possible to work around this limitation 
    by dynamically allocating a new array, copying the elements over, and deleting the old array. However, this is error prone, 
    especially when the element type is a class (which have special rules governing how they are created).

    Consequently, we recommend avoiding doing this yourself.

    Fortunately, if you need this capability, C++ provides a resizable array as part of the standard library called std::vector. 
    We’ll introduce std::vector shortly.
    */

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Remove the extraneous newline character so getline() doesn't think we entered an empty string
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Question #1

    Write a program that:
    * Asks the user how many names they wish to enter.
    * Dynamically allocates a std::string array.
    * Asks the user to enter each name.
    * Calls std::sort to sort the names (See 10.4 -- Sorting an array using selection sort and 10.11 -- Pointer arithmetic and 
    * array indexing)
    * Prints the sorted list of names.

    std::string supports comparing strings via the comparison operators < and >. You don’t need to implement string comparison 
    by hand.

    Your output should match this:

    How many names would you like to enter? 5
    Enter name #1: Jason
    Enter name #2: Mark
    Enter name #3: Alex
    Enter name #4: Chris
    Enter name #5: John

    Here is your sorted list:
    Name #1: Alex
    Name #2: Chris
    Name #3: Jason
    Name #4: John
    Name #5: Mark

    A reminder

    You can use std::getline() to read in names that contain spaces (see lesson 4.12 -- An introduction to std::string).

    A reminder

    To use std::sort() with a pointer to an array, calculate begin and end manually

    std::sort(array, array + arrayLength);
    */
    int number_of_names{ how_many() };
    std::string* string_array{ new std::string[number_of_names]{} };

    for(int count{ 0 }; count != number_of_names; ++count)
    {
        std::cout << "Enter name #" << (count+1) << ": ";
        std::getline( std::cin >> std::ws, string_array[count] );
    }
    
    std::sort(string_array, string_array + number_of_names);
    std::cout << std::endl;

    std::cout << "Here is your sorted list: \n";
    for(int count{ 0 }; count != number_of_names; ++count)
    {
        std::cout << "Name #" << (count+1) << ": ";
        std::cout << string_array[count] << '\n';
    }
    std::cout << std::endl;

    delete[] string_array;



    return 0;
}