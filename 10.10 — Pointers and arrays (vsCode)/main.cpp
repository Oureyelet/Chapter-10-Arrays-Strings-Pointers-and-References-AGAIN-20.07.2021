#include <iostream>
#include "functions.h"

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

    /*
    Note that we’re not actually indirecting through the array itself. The array (of type int[5]) gets implicitly converted into a pointer (of type int*), and we use indirection through the pointer to get the value at the memory address the pointer is holding (the value of the first element of the array).

    We can also assign a pointer to point at the array:
    */
    int* ptr_array{ array };
    std::cout << *ptr_array << '\n';
    //This works because the array decays into a pointer of type int*, and our pointer (also of type int*) has the same type.


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Differences between pointers and fixed arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    There are a few cases where the difference in typing between fixed arrays and pointers makes a difference. 
    These help illustrate that a fixed array and a pointer are not the same.

    The primary difference occurs when using the sizeof() operator. When used on a fixed array, sizeof returns the size of 
    the entire array (array length * element size). When used on a pointer, sizeof returns the size of a memory 
    address (in bytes). The following program illustrates this:
    */
    int array_one[]{9, 7, 5, 3, 1};

    int* ptr_array_one{ array_one };

    std::cout << sizeof( array_one ) << '\n';
    std::cout << sizeof( *ptr_array_one ) << '\n';

    /*
    A fixed array knows how long the array it is pointing to is. A pointer to the array does not.

    The second difference occurs when using the address-of operator (&). Taking the address of a pointer yields the memory 
    address of the pointer variable. Taking the address of the array returns a pointer to the entire array. 
    This pointer also points to the first element of the array, but the type information is different (in the above example, 
    the type of &array is int(*)[5]). It’s unlikely you’ll ever need to use this.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Revisiting passing fixed arrays to functions" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Back in lesson 10.2 -- Arrays (Part II), we mentioned that because copying large arrays can be very expensive, 
    C++ does not copy an array when an array is passed into a function. When passing an array as an argument to a function, 
    a fixed array decays into a pointer, and the pointer is passed to the function:
    */
    int array_two[]{ 1, 1, 2, 3, 5, 8, 13, 21 };

    std::cout << sizeof(array_two) << '\n'; // will print sizeof(int) * array length
    printSize(array_two);// the array argument decays into a pointer here

    //Note that this happens even if the parameter is declared as a fixed array:
    std::cout << sizeof(array_two) << '\n'; // will print sizeof(int) * array length
    printSize(array_two); // the array argument decays into a pointer here

    /*
    In the above example, C++ implicitly converts parameters using the array syntax ([]) to the pointer syntax (*). 
    That means the following two function declarations are identical:
    void printSize(int array[]);
    void printSize(int* array);
    */


    /*
    Best practice

    Favor the pointer syntax (*) over the array syntax ([]) for array function parameters.
    Because it makes it clear that the parameter is being treated as a pointer, not a fixed array.
    */ 
    

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "An intro to pass by address" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    https://www.learncpp.com/cpp-tutorial/pointers-and-arrays/
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Arrays in structs and classes don’t decay" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Finally, it is worth noting that arrays that are part of structs or classes do not decay when the whole struct or 
    class is passed to a function. This yields a useful way to prevent decay if desired, and will be valuable later when we 
    write classes that utilize arrays.

    In the next lesson, we’ll take a look at pointer arithmetic, and talk about how array indexing actually works.
    */

    return 0;
}