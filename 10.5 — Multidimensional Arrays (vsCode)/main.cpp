#include <iostream>

int main()
{
    std::cout << "Hello World\n";

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Multidimensional array" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    The elements of an array can be of any data type, including arrays! An array of arrays 
    is called a multidimensional array.
    */
    int array[3][5];// a 3-element array of 5-element arrays


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing two-dimensional arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    To initialize a two-dimensional array, it is easiest to use nested braces, with each set of 
    numbers representing a row:
    */
    int array_1[3][5]
    {
        { 1, 2, 3, 4, 5 }, // row 0
        { 6, 7, 8, 9, 10 }, // row 1
        { 11, 12, 13, 14, 15 } // row 2
    };


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Accessing elements in a two-dimensional array" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Accessing all of the elements of a two-dimensional array requires two loops: one for the row, 
    and one for the column. Since two-dimensional arrays are typically accessed row by row, the row 
    index is typically used as the outer loop.
    */
    constexpr int numRow{ 3 };
    constexpr int numCol{ 5 };
    //constexpr creates a compile-time constant; const simply means that value cannot be changed.

    for(int row{ 0 }; row < numRow; ++row)
    {
        for(int col{ 0 }; col < numCol; ++col)
        {
            std::cout << array_1[row][col] << ' ';
        }
    }
    std::cout << std::endl;


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Multidimensional arrays larger than two dimensions" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Multidimensional arrays may be larger than two dimensions. Here is a declaration of a 
    three-dimensional array:
    */
    int array_2[3][5][10];


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "A two-dimensional array example" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Let’s take a look at a practical example of a two-dimensional array:
    */
    constexpr int numRows{ 10 };
    constexpr int numCols{ 10 };

    // Declare a 10x10 array
    int product[numRows][numCols]{};

    // Calculate a multiplication table
    for(int row{ 1 }; row < numRows; ++row)
    {
        for(int col{ 1 }; col < numCols; ++col)
        {
            product[row][col] = row * col;
        }
    }

    for(int row{ 1 }; row < numRows; ++row)
    {
        for(int col{ 1 }; col < numCols; ++col)
        {
            std::cout << product[row][col] << '\t';
        }
    std::cout << '\n';
    }



    return 0;
}