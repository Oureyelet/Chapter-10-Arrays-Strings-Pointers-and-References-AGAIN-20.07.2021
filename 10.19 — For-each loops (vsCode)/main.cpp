#include <iostream>
#include <iterator> // for std::size()
#include <string> // std::string
#include <vector> // for std::vector
#include <string_view> // for std::string_view

int sumArray(const int array[])// array is a pointer here
{
    int sum{ 0 };
/*
    for(auto number : array) // compile error, the size of array isn't known
    {
        sum += number;
    }
*/

    return sum;
}


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

    std::cout << ptr_arrayA << '\n'; // print address 0x7fffffffd684
    std::cout << *ptr_arrayA << '\n'; // print first index of array
    std::cout << &ptr_arrayA << '\n';// print addres 0x7fffffffd5f0
    std::cout << array_A << '\n';// print 0x7fffffffd684
    std::cout << &array_A << '\n';//print 0x7fffffffd684
    std::cout << *array_A << '\n';// print first index of array


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For-each loops and non-arrays" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    For-each loops don’t only work with fixed arrays, they work with many kinds of list-like structures, 
    such as vectors (e.g. std::vector), linked lists, trees, and maps. We haven’t covered any of these yet, 
    so don’t worry if you don’t know what these are. Just remember that for each loops provide a flexible and generic 
    way to iterate through more than just arrays.
    */
    std::vector fibonaci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };// note use of std::vector here rather than a fixed array
    // Before C++17
    // std::vector<int> fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for(auto& number : fibonaci)
    {
        std::cout << number << ' ';
    }
    std::cout << std::endl;


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "For-each doesn’t work with pointers to an array" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    In order to iterate through the array, for-each loop needs to know how big the array is, which means knowing the array size. 
    Because arrays that have decayed into a pointer do not know their size, for-each loops will not work with them!
    */
    constexpr int array_tt[]{ 9, 7, 5, 3, 1 };

    //std::cout << sumArray(array_tt) << '\n'; // array decays into a pointer here

    //Similarly, dynamic arrays won’t work with for-each loops for the same reason.


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Can I get the index of the current element?" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    For-each loops do not provide a direct way to get the array index of the current element. This is because many of the 
    structures that for-each loops can be used with (such as linked lists) are not directly indexable!

    Since C++20, range-based for-loops can be used with an init-statement just like the init-statement in if-statements. 
    We can use the init-statement to create a manual index counter without polluting the function in which the 
    for-loop is placed.

    The init-statement is placed right before the loop variable:

    for (init-statement; element_declaration : array)
    statement;

    In the following code, we have two arrays which are correlated by index. For example, the student with the name at 
    names[3] has a score of scores[3]. Whenever a student with a new high score is found, we print their name and 
    difference in points to the previous high score.
    */
    std::string names2[]{ "Alex", "Betty", "Caroline", "Dave", "Emily" };
    constexpr int scores2[]{ 84, 92, 76, 81, 56 };
    int maxScore2{ 0 };

    for(int i{ 0 }; auto number : scores2)
    {
        if( number > maxScore2 )
        {
            std::cout << names2[i] << " beat the previous best score of " << maxScore2 << " by " << 
            (number - maxScore2) << " points!\n";
            maxScore2 = number;
        }
        ++i;
    }
    std::cout << "The best score was " << maxScore2 << '\n';
    /*
    The int i{ 0 }; is the init-statement, it only gets executed once when the loop starts. At the end of each iteration, 
    we increment i, similar to a normal for-loop. However, if we were to use continue inside the loop, the ++i would get 
    skipped, leading to unexpected results. If you use continue, you need to make sure that i gets incremented before the 
    continue is encountered.

    Before C++20, the index variable i had to be declared outside of the loop, which could lead to name conflicts when we 
    wanted to define another variable named i later in the function.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Conclusion" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    For-each loops provide a superior syntax for iterating through an array when we need to access all of the array 
    elements in forwards sequential order. It should be preferred over the standard for loop in the cases where it can be used. 
    To prevent making copies of each element, the element declaration should ideally be a reference.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Question #1

    Declare a fixed array with the following names: Alex, Betty, Caroline, Dave, Emily, Fred, Greg, and Holly. 
    Ask the user to enter a name. Use a for each loop to see if the name the user entered is in the array.

    Sample output:

    Enter a name: Betty
    Betty was found.

    Enter a name: Megatron
    Megatron was not found.

    Hint: Use std::string_view as your array type.
    */
    constexpr std::string_view name_Q[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::string user_input{};

    std::cout << "Enter a name: ";
    std::cin >> user_input;

    bool check{ false };

    for(auto& index : name_Q)
    {
        if(index == user_input)
        {
            check = true;
        }
    }

    if(check != false)
    {
        std::cout << user_input <<  " was found." << '\n';
    }
    else
    {
        std::cout << user_input << " was not found." << '\n';
    }


    return 0;
}