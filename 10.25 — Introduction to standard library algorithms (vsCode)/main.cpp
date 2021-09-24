#include <iostream>
#include <algorithm> // for iterators begin and end
#include <array> // for std::array
#include <string_view> // for std::string_view
#include <functional> //for std::greater{};

// function prototype:
bool containsNut(std::string_view);
bool greater(int,int);
void doubleNumber(int&);

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
    std::array<std::string_view, 9> str_arr{ "apple", "banana", "walnut", "lemon", "apple", "banana", "walnut", "lemon", "peanut" };

    // Scan our array to see if any elements contain the "nut" substring
    auto str_found{ std::find_if( str_arr.begin(), str_arr.end(), containsNut) };    

    if( str_found == str_arr.end() )
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *str_found << '\n';
    }
    /*
    If you were to write the above example by hand, you’d need at least three loops (one to loop through the array, 
    and two to match the substring). The standard library functions allow us to do the same thing in just a few lines of code!
    */
    

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::count and std::count_if to count how many occurrences there are" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::count and std::count_if search for all occurrences of an element or an element fulfilling a condition.

    In the following example, we’ll count how many elements contain the substring “nut”:
    */
    auto find_nut{std::count_if( str_arr.begin(), str_arr.end(), containsNut )};

    std::cout << "Counted " << find_nut << " nut(s)\n";

    
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::sort to custom sort" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    We previously used std::sort to sort an array in ascending order, but std::sort can do more than that. 
    There’s a version of std::sort that takes a function as its third parameter that allows us to 
    sort however we like. The function takes two parameters to compare, and returns true if the first argument 
    should be ordered before the second. By default, std::sort sorts the elements in ascending order.

    Let’s use std::sort to sort an array in reverse order using a custom comparison function named greater:
    */
    std::array sort_arr{ 13, 90, 99, 5, 40, 80, 132, 903, 995, 57, 407, 803 };

    std::sort( sort_arr.begin(), sort_arr.end(), greater ); 

    for(int i : sort_arr)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    
    /*
    Once again, instead of writing our own custom loop functions, we can sort our array however we like in just a few 
    lines of code!

    Our greater function needs 2 arguments, but we’re not passing it any, so where do they come from? When we use a 
    function without parentheses (), it’s only a function pointer, not a call. You might remember this from when we 
    tried to print a function without parentheses and std::cout printed “1”. std::sort uses this pointer and calls 
    the actual greater function with any 2 elements of the array. We don’t know which elements greater will be called with, 
    because it’s not defined which sorting algorithm std::sort is using under the hood. We talk more about function pointers 
    in a later chapter.
    */

    /*
    Tip!

    Because sorting in descending order is so common, C++ provides a custom type (named std::greater) for that too 
    (which is part of the functional header). In the above example, we can replace:

    std::sort(arr.begin(), arr.end(), greater); // call our custom greater function

    with:

    std::sort(arr.begin(), arr.end(), std::greater{}); // use the standard library greater comparison
    // Before C++17, we had to specify the element type when we create std::greater
    std::sort(arr.begin(), arr.end(), std::greater<int>{}); // use the standard library greater comparison

    Note that the std::greater{} needs the curly braces because it is not a callable function. It’s a type, and in 
    order to use it, we need to instantiate an object of that type. The curly braces instantiate an anonymous object 
    of that type (which then gets passed as an argument to std::sort). 
    */
    std::sort( sort_arr.begin(), sort_arr.end(), std::greater{} );

    for(int i : sort_arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using std::for_each to do something to all elements of a container" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::for_each takes a list as input and applies a custom function to every element. This is useful when we want to 
    perform the same operation to every element in a list.

    Here’s an example where we use std::for_each to double all the numbers in an array:
    */
    std::array each_array{ 1, 2, 3, 4 };

    std::for_each(each_array.begin(), each_array.end(), doubleNumber);

    for(int i : each_array)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    /*
    This often seems like the most unnecessary algorithm to new developers, because equivalent code with a 
    range-based for-loop is shorter and easier. But there are benefits to std::for_each. Let’s compare std::for_each to a 
    range-based for-loop.
    */


    return 0;
}
void doubleNumber(int& x)
{
    x *= 2;
}

bool greater(int a, int b)
{
    // Order @a before @b if @a is greater than @b.
    return ( a < b );
}

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
    // std::string_view::find returns std::string_view::npos if it doesn't find
    // the substring. Otherwise it returns the index where the substring occurs
    // in str.
    return ( str.find("nut") != std::string_view::npos );
    /*
    std::string_view::npos it means not found. It is usually defined like so:
    static const size_t npos = -1;
    It is better to compare to npos instead of -1 because the code is more legible.
    */
}
