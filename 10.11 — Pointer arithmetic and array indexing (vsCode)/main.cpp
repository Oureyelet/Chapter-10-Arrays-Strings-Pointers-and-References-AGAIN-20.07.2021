#include <iostream>
#include <iterator> // for std::size(), std::begin, std::end
#include <algorithm> // for std::count_it, std::find
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

    for(char* ptr{ name }; ptr != (name + arrayLenght); ++ptr)
    {
        if(isVowel(*ptr))
            ++ourVowel;
    }

    std::cout << name << " has " << ourVowel << " vowels\n";
    /*
    How does it work? This program uses a pointer to step through each of the elements in an array. 
    Remember that arrays decay to pointers to the first element of the array. So by assigning ptr to name, ptr will also 
    point to the first element of the array. Indirection through ptr is performed for each element when we call isVowel(*ptr), 
    and if the element is a vowel, numVowels is incremented. Then the for loop uses the ++ operator to advance the pointer to 
    the next character in the array. The for loop terminates when all characters have been examined.
    */


    /*
    Because counting elements is common, the algorithms library offers std::count_if, which counts elements that fulfill a condition. 
    We can replace the for-loop with a call to std::count_if.
    */
    char surname[]{ "Kacperscy" };

    // walk through all the elements of name and count how many calls to isVowel return true
    auto numVowels{ std::count_if(std::begin(surname), std::end(surname), isVowel) };

    std::cout << surname << " has " << numVowels << " vowels.\n";


    /*
    std::begin returns an iterator (pointer) to the first element, while std::end returns an iterator to the element that 
    would be one after the last. The iterator returned by std::end is only used as a marker, accessing it causes undefined 
    behavior, because it doesn’t point to a real element.

    std::begin and std::end only work on arrays with a known size. If the array decayed to a pointer, we can calculate begin 
    and end manually.
    */
    auto calculate_manually{ std::count_if( surname, surname + 9, isVowel ) };
    std::cout << calculate_manually << '\n';
    /*
    Note that we’re calculating name + nameLength, not name + nameLength - 1, because we don’t want the last element, 
    but the pseudo-element one past the last.

    Calculating begin and end of an array like this works for all algorithms that need a begin and end argument.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////////" << '\n';
    std::cout << "QUIZ TIME !" << '\n';
    std::cout << "/////////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////////
    /*
    Question #1
    Why does the following code work?

    #include <iostream>

    int main()
    {
        int arr[]{ 1, 2, 3 };

        std::cout << 2[arr] << '\n';

        return 0;
    }

    answer is:
    The subscript operator ([]) is identical to an addition and an indirection, the operands can be swapped.

    arr[2]
    // same as
    *(arr + 2)
    // same as
    *(2 + arr)
    // same as
    2[arr]

    It’s an interesting observation, but don’t use this syntax in real code. This only works for the built-in subscript operator. 
    You’ll learn about types with custom operators where this doesn’t work later. 
    */

    /*
    Write a function named find that takes a pointer to the beginning and a pointer to the end (1 element past the last) of an array, as well as a value. The function should search for the given value and return a pointer to the first element with that value, or the end pointer if no element was found. The following program should run:

    #include <iostream>
    #include <iterator>

    // ...

    int main()
    {
        int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

        // Search for the first element with value 20.
        int* found{ find(std::begin(arr), std::end(arr), 20) };

        // If an element with value 20 was found, print it.
        if (found != std::end(arr))
        {
            std::cout << *found << '\n';
        }

        return 0;
    }
    */
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ find(std::begin(arr), std::end(arr), 20) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    /*
    My onw task:
    */

    int my_array[]{ 2, 5, 6, 3, 45, 78, 34, 77, 3434, 89 };

    auto my_found{ std::find(std::begin(my_array), std::end(my_array), 77) };

    if(my_found != std::end(my_array))
    {
        std::cout << *my_found << '\n';
    }

    return 0;
}