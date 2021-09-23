#include <iostream>
#include <algorithm> // for iterators begin and end
#include <array> // for std::array


int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Introduction to standard library algorithms" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    New programmers typically spend a lot of time writing custom loops to perform relatively simple tasks, such as 
    sorting or counting or searching arrays. These loops can be problematic, both in terms of how easy it is to make an 
    error, and in terms of overall maintainability, as loops can be hard to understand.

    Because searching, counting, and sorting are such common operations to do, the C++ standard library comes with a bunch 
    of functions to do these things in just a few lines of code. Additionally, these standard library functions come 
    pre-tested, are efficient, work on a variety of different container types, and many support parallelization 
    (the ability to devote multiple CPU threads to the same task in order to complete it faster).

    The functionality provided in the algorithms library generally fall into one of three categories:

        Inspectors -- Used to view (but not modify) data in a container. Examples include searching and counting.
        Mutators -- Used to modify data in a container. Examples include sorting and shuffling.
        Facilitators -- Used to generate a result based on values of the data members. Examples include objects that 
        multiply values, or objects that determine what order pairs of elements should be sorted in. 

    These algorithms live in the algorithms library. In this lesson, we’ll explore some of the more common algorithms -- 
    but there are many more, and we encourage you to read through the linked reference to see everything that’s available!

    Note: All of these make use of iterators, so if you’re not familiar with basic iterators, please review lesson 10.24 -- 
    Introduction to iterators.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::find to find an element by value" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::find searches for the first occurrence of a value in a container. std::find takes 3 parameters: 
    an iterator to the starting element in the sequence, an iterator to the ending element in the sequence, 
    and a value to search for. It returns an iterator pointing to the element (if it is found) or the end of 
    the container (if the element is not found).

    For example:
    */
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    std::cout << "Enter a value to search for and replace with: ";
    int search{};
    int replace{};
    std::cin >> search >> replace;

    // Input validation omitted

    // std::find returns an iterator pointing to the found element (or the end of the container)
    // we'll store it in a variable, using type inference to deduce the type of
    // the iterator (since we don't care)
    auto found{ std::find(std::begin(arr), std::end(arr), search) };

    // Algorithms that don't find what they were looking for return the end iterator.
    // We can access it by using the end() member function.
    if(found == std::end(arr))
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        // Override the found element.
        *found = replace;
    }

    for(int i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::find_if to find an element that matches some condition" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Sometimes we want to see if there is a value in a container that matches some condition 
    (e.g. a string that contains a specific substring) rather than an exact value. In such cases, 
    std::find_if is perfect. The std::find_if function works similarly to std::find, but instead of 
    passing in a value to search for, we pass in a callable object, such as a function pointer 
    (or a lambda, which we’ll cover later) that checks to see if a match is found. std::find_if will call this 
    function for every element until a matching element is found (or no more elements remain in the container to check).

    Here’s an example where we use std::find_if to check if any elements contain the substring “nut”:
    */
    









    return 0;
}