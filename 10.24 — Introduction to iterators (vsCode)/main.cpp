#include <array>
#include <cstddef>
#include <iostream>

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << " Introduction to iterators" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Iterating through an array (or other structure) of data is quite a common thing to do in programming. And so far, 
    we’ve covered many different ways to do so: with loops and an index (for-loops and while loops), with pointers and 
    pointer arithmetic, and with range-based for-loops:
    */


    // In C++17, the type of variable data is deduced to std::array<int, 7>
    // If you get an error compiling this example, see the warning below
    std::array<int, 7> data{ 0, 1, 2, 3, 4, 5, 6 };
    std::size_t lenght{ data.size() };

    // while-loop with explicit index
    std::size_t index{ 0 };
    while (index != lenght)
    {
        std::cout << data[index] << ' ';
        ++index;
    }
    std::cout << '\n';
    
    // for-loop with explicit index
    for(int i{ 0 }; i != lenght; ++i)
    {
         std::cout << data[i] << ' ';
    }
    std::cout << '\n';

    // for-loop with pointer (Note: ptr can't be const, because we increment it)
    for(auto ptr{ &data[0] }; ptr != (&data[0] + lenght); ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << std::endl;
    
    // ranged-based for loop
    for(const auto& element : data)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    /*
    Warning

    The examples in this lesson use a C++17 feature called class template argument deduction to deduce the template 
    arguments for a template variable from its initializer. In the example above, when the compiler sees 
    std::array data{ 0, 1, 2, 3, 4, 5, 6 };, it will deduce that we want std::array<int, 7> data { 0, 1, 2, 3, 4, 5, 6 };.

    If your compiler is not C++17 enabled, you’ll get an error that says something like, “missing template arguments before 
    ‘data’”. In that case, your best bet is to enable C++17, as per lesson 0.12 -- Configuring your compiler: 
    Choosing a language standard. If you can not, you can replace the lines that use class template argument deduction with 
    lines that have explicit template arguments (e.g. replace std::array data{ 0, 1, 2, 3, 4, 5, 6 }; 
    with std::array<int, 7> data { 0, 1, 2, 3, 4, 5, 6 }; 
    */

    /*
    Looping using indexes is more typing than needed if we only use the index to access elements. 
    It also only works if the container (e.g. the array) provides direct access to elements (which arrays do, but 
    some other types of containers, such as lists, do not).

    Looping with pointers and pointer arithmetic is verbose, and can be confusing to readers who don’t know the rules of 
    pointer arithmetic. Pointer arithmetic also only works if elements are consecutive in memory (which is true for arrays, 
    but not true for other types of containers, such as lists, trees, and maps).

    For advanced readers

    Pointers (without pointer arithmetic) can also be used to iterate through some non-sequential structures. In a linked list, 
    each element is connected to the prior element by a pointer. We can iterate through the list by following the 
    chain of pointers.

    Range-based for-loops are a little more interesting, as the mechanism for iterating through our container 
    is hidden -- and yet, they still work for all kinds of different structures (arrays, lists, trees, maps, etc…). 
    How do these work? They use iterators.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Iterators" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    An iterator is an object designed to traverse through a container (e.g. the values in an array, or the 
    characters in a string), providing access to each element along the way.

    A container may provide different kinds of iterators. For example, an array container might offer a forwards 
    iterator that walks through the array in forward order, and a reverse iterator that walks through the array 
    in reverse order.

    Once the appropriate type of iterator is created, the programmer can then use the interface provided 
    by the iterator to traverse and access elements without having to worry about what kind of traversal 
    is being done or how the data is being stored in the container. And because C++ iterators typically 
    use the same interface for traversal (operator++ to move to the next element) and access 
    (operator* to access the current element), we can iterate through a wide variety of 
    different container types using a consistent method.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointers as an iterator" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    The simplest kind of iterator is a pointer, which (using pointer arithmetic) works for data 
    stored sequentially in memory. Let’s revisit a simple array traversal using a pointer and pointer arithmetic:
    */
    std::array myData{ 0, 1, 2, 3, 4, 5, 6 };

    auto begin{ &myData[0] };
    // note that this points to one spot beyond the last element
    auto end{ begin + std::size(myData) };

    for(auto ptr{ begin }; ptr != end; ++ptr)// ++ to move to next element
    {
        std::cout << *ptr << ' '; // Indirection to get value of current element
    }
    std::cout << std::endl;

    /*

    In the above, we defined two variables: begin (which points to the beginning of our container), and end 
    (which marks an end point). For arrays, the end marker is typically the place in memory where the last element would 
    be if the container contained one more element.

    The pointer then iterates between begin and end, and the current element can be accessed by 
    indirection through the pointer.

    Warning

    You might be tempted to calculate the end marker using the address-of operator and array syntax like so:

    int* end{ &array[std::size(array)] };

    But this causes undefined behavior, because array[std::size(array)] accesses an element that is off the end of the array.

    Instead, use:

    int* end{ array.data() + std::size(array) }; // data() returns a pointer to the first element
    */
    

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Standard library iterators" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */


    return 0;
}