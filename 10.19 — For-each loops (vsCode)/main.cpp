#include <iostream>
#include <iterator> // for std::size()
#include <string> // std::string


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

    int maxScores{ 0 };// keep track of our largest score
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
    The for-each statement has a syntax that looks like this:

    for (element_declaration : array)
    statement;

    When this statement is encountered, the loop will iterate through each element in array, assigning the 
    value of the current array element to the variable declared in element_declaration. For best results, 
    element_declaration should have the same type as the array elements, otherwise type conversion will occur.

    Let’s take a look at a simple example that uses a for-each loop to print all of the elements in 
    an array named fibonacci:
    */
    constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for( int number : fibonacci )// iterate over array fibonacci    
    {
        std::cout << number << ' ';// we access the array element for this iteration through variable number
    }
    std::cout << std::endl;
    /*
    Let’s take a closer look at how this works. First, the for loop executes, and variable number is set to the value of 
    the first element, which has value 0. The program executes the statement, which prints 0. Then the for loop executes 
    again, and number is set to the value of the second element, which has value 1. The statement executes again, 
    which prints 1. The for loop continues to iterate through each of the numbers in turn, executing the statement for each 
    one, until there are no elements left in the array to iterate over. At that point, the loop terminates, and the program 
    continues execution (returning 0 to the operating system).

    Note that variable number is not an array index. It’s assigned the value of the array element for the 
    current loop iteration.

    Because element_declaration should have the same type as the array elements, this is an ideal case in which to use the 
    auto keyword, and let C++ deduce the type of the array elements for us.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For-each loops and references" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the following for-each example, our element declarations are declared by value:
    */
    std::string array[]{ "peter", "likes", "frozen", "yogurt" };
    for(auto element : array)// element will be a copy of the current array element
    {
        std::cout << element << ' ';
    }

    std::cout << '\n';
    /*
    This means each array element iterated over will be copied into variable element. 
    Copying array elements can be expensive, and most of the time we really just want to refer to the original element. 
    Fortunately, we can use references for this:
    */
    std::string names[]{ "Ania", "Kamila", "Robert", "Holly", "Dacjan", "Mateusz" };
    // The ampersand makes element a reference to the actual array element, preventing a copy from being made
    for(auto& element : names)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    /*
    In the above example, element will be a reference to the currently iterated array element, avoiding having to make a copy. 
    Also any changes to element will affect the array being iterated over, something not possible if 
    element is a normal variable.

    And, of course, it’s a good idea to make your reference const if you’re intending to use it in a 
    read-only fashion:
    */
    std::string bejbe[]{ "Ania", "Bejbe", "Ponczkowa" };
    for(const auto& element : bejbe)// element is a const reference to the currently iterated array element
    {
        std::cout << element << '\n';
    }
    /*
    Best practice:

    In for-each loops element declarations, if your elements are non-fundamental types, use references or const 
    references for performance reasons. 
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Rewriting the max scores example using a for-each loop" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Here’s the example at the top of the lesson rewritten using a for each loop:
    */
    const int our_scores[]{ 84, 92, 76, 81, 56 };
    int max_Scores{ 0 };// keep track of our largest score

    for(auto score : our_scores)// iterate over array scores, assigning each value in turn to variable score
    {
        if( score > max_Scores )
        {
            max_Scores = score;
        }
    }
    std::cout << "The best score was " << max_Scores << '\n';
    /*
    Note that in this example, we no longer have to manually subscript the array or get its size. 
    We can access the array element directly through variable score. The array has to have size information. 
    An array that decayed to a pointer cannot be used in a for-each loop.
    */

    int array_A[]{ 1, 3, 5 };

    int* ptr_arrayA{ array_A };

    std::cout << ptr_arrayA << '\n'; // print address of
    std::cout << *ptr_arrayA << '\n';
    std::cout << &ptr_arrayA << '\n';
    std::cout << array_A << '\n';
    std::cout << &array_A << '\n';
    std::cout << *array_A << '\n';


    return 0;
}