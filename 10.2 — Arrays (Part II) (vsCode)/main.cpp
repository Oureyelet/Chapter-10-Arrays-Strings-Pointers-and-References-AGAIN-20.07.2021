#include <iostream>
#include <iterator> //for std::size

enum StudentNames
{
    kenny, // 0
    kyle, // 1
    stan, // 2
    butters, // 3
    cartman, // 4

    max_students // 5
};

namespace Animals
{
    enum Animals
    {
        chicken, 
        dog,
        cat,
        elephant,
        duck, 
        snake,

        max_Animal,
    };
}

int main()
{
    std::cout << "Hello World\n";

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing fixed arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    One way to “initialize” an array is to do it element by element:
    */
    int prime[5];// hold the first 5 prime numbers
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11;

    /*
    The following example initializes the array with the same values as the one above:
    */
    int prime_2[5]{2, 3, 5, 7, 11};// use initializer list to initialize the fixed array

    /*
    zero initialization:
    */
    int prime_3[5]{2, 3, 5};// only initialize first 3 elements
    
    std::cout << prime_3[2] << ' ' << prime_3[3] << ' ' << prime_3[4] << "\n";


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Omitted length" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    If you are initializing a fixed array of elements using an initializer list, 
    the compiler can figure out the length of the array for you, and you can omit 
    explicitly declaring the length of the array.

    The following two lines are equivalent:
    */
    int prime_4[5]{2, 5, 7, 5, 8};// explicitly define the length of the array
    int prime_5[]{2, 5, 7, 5, 8};// let the initializer list set length of the array
    

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Arrays and enums" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    one enumerator maps to each of the possible array indices:
    */
    int testScores[StudentNames::max_students]{};// allocate 5 integers
    //look above main function for our enum.

    testScores[StudentNames::stan] = 137;

    std::cout << "Stan had: " << testScores[StudentNames::stan] << " scores\n";


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Arrays and enum classes" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Enum classes don’t have an implicit conversion to integer. If you try it you’ll get a compiler error. 
    This can be addressed by using a static_cast to convert the enumerator to an integer.
    */

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Passing arrays to functions" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    for see more go: https://www.learncpp.com/cpp-tutorial/arrays-part-ii/
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Determining the length of an array" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    The std::size() function from the <iterator> header can be used to determine the length of arrays.

    Here’s an example:
    */
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21, 23 };
    std::cout << "The array has: " << std::size(array) << " elements\n";


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Indexing an array out of range" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Rule:

    When using arrays, ensure that your indices are valid for the range of your array!
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time !" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    1) Declare an array to hold the high temperature (to the nearest tenth of a degree) for each day 
    of a year (assume 365 days in a year). Initialize the array with a value of 0.0 for each day.

    2) Set up an enum with the names of the following animals: chicken, dog, cat, elephant, duck, 
    and snake. Put the enum in a namespace. Define an array with an element for each of these animals, 
    and use an initializer list to initialize each element to hold the number of legs that animal has.

    Write a main function that prints the number of legs an elephant has, using the enumerator.
    */
    double temp[365]{ 0.0 };

    int legs[Animals::max_Animal]{2, 4, 4, 4, 2};
    std::cout << "Elephant has " << legs[Animals::elephant] << " legs.\n";




    return 0;
}