#include <iostream>
#include <iterator> // for std::size()

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For-each loops" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    In lesson 10.3 -- Arrays and loops, we showed examples where we used a for loop to iterate through each element of an array.

    For example:
    */
    constexpr int scores[]{  84, 92, 76, 81, 56  };
    constexpr int numStudents{ std::size(scores) };

    int maxScores{ 0 };
    for(int index{ 0 }; index != numStudents; ++index)
    {
        if(scores[index] > maxScores)
        {
            maxScores = scores[index];
        }
    }
    std::cout << "The best score was " << maxScores << '\n';
    /*
    While for loops provide a convenient and flexible way to iterate through an array, they are also easy to mess up and prone 
    to off-by-one errors.

    There’s a simpler and safer type of loop called a for-each loop (also called a range-based for-loop) for cases where we 
    want to iterate through every element in an array (or other list-type structure).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For-each loops" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */


    return 0;
}