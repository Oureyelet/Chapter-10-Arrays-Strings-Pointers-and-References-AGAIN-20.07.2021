#include <iostream>
#include <iterator> // for std::size()
#include "functions.h"

int main()
{
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointer arithmetic" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    The C++ language allows you to perform integer addition or subtraction operations on pointers. If ptr points to an integer, 
    ptr + 1 is the address of the next integer in memory after ptr. ptr - 1 is the address of the previous integer before ptr.

    Note that ptr + 1 does not return the memory address after ptr, but the memory address of the next object of the type that 
    ptr points to. If ptr points to an integer (assuming 4 bytes), ptr + 3 means 3 integers (12 bytes) after ptr. If ptr points 
    to a char, which is always 1 byte, ptr + 3 means 3 chars (3 bytes) after ptr.

    When calculating the result of a pointer arithmetic expression, the compiler always multiplies the integer operand by the 
    size of the object being pointed to. This is called scaling.

    Consider the following program:
    */
    int value{ 7 };
    int* ptr_value{ &value };

    std::cout << ptr_value + 1 << '\n';
    std::cout << ptr_value + 2 << '\n';
    std::cout << ptr_value + 3 << '\n';
    std::cout << ptr_value + 4 << '\n';
    /*
    As you can see, each of these addresses differs by 4 (7C + 4 = 80 in hexadecimal). 
    This is because an integer is 4 bytes on the author’s machine.
    */

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Arrays are laid out sequentially in memory" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    By using the address-of operator (&), we can determine that arrays are laid out sequentially in memory. That is, 
    elements 0, 1, 2, … are all adjacent to each other, in order.
    */
    int array[]{9, 7, 5, 3, 1};

    std::cout << "Element 0 is at address: " << &array[0] << '\n';
    std::cout << "Element 1 is at address: " << &array[1] << '\n';
    std::cout << "Element 2 is at address: " << &array[2] << '\n';
    std::cout << "Element 3 is at address: " << &array[3] << '\n';
    std::cout << "Element 4 is at address: " << &array[4] << '\n';
    //Note that each of these memory addresses is 4 bytes apart, which is the size of an integer on the author’s machine.


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointer arithmetic, arrays, and the magic behind indexing" << '\n';
    std::cout << "/////////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////////
    /*
    In the section above, you learned that arrays are laid out in memory sequentially.

    In the previous lesson, you learned that a fixed array can decay into a pointer that points to the first element (element 0) 
    of the array.

    Also in a section above, you learned that adding 1 to a pointer returns the memory address of the next object of that type in 
    memory.

    Therefore, we might conclude that adding 1 to an array should point to the second element (element 1) of the array. 
    We can verify experimentally that this is true:
    */
    int array_one[]{ 9, 7, 5, 3, 1 };

    std::cout << &array_one[1] << '\n';// print memory address of array element 1
    std::cout << array_one+1 << '\n';// print memory address of array pointer + 1

    std::cout << array_one[1] << '\n';//print 7
    std::cout << *(array_one+1) << '\n';// prints 7 (note the parenthesis required here)
    /*
    Note that when performing indirection through the result of pointer arithmetic, parenthesis are necessary to ensure the 
    operator precedence is correct, since operator * has higher precedence than operator +.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using a pointer to iterate through an array" << '\n';
    std::cout << "/////////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////////
    /*
    We can use a pointer and pointer arithmetic to loop through an array. Although not commonly done this way 
    (using subscripts is generally easier to read and less error prone), the following example goes to show it is possible:
    */
    char name[]{"Mollie"};
    int arrayLenght{ static_cast<int>(std::size(name)) };
    int ourVowel{ 0 };

    for(char* ptr{ name }; name != arrayLenght; ++name)
    {
        if(isVowel)
            ++ourVowel
        else
    }


    return 0;
}