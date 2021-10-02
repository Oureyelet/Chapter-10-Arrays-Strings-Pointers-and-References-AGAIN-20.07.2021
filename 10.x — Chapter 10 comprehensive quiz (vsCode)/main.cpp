#include <iostream>
#include <algorithm> // for std::shuffle, sort
#include <array>
#include <ctime>
#include <numeric> // for std::reduce
#include <random>
#include <string_view>
#include <cstdlib> // for std::size_t
#include <limits>//for: std::cin.ignore


//funtion prototype:
int countTotalItems(const std::array<int, 3>&);

struct StudentNameGrade
{
    std::string name{};
    int grade{};
};

bool my_sort(const StudentNameGrade& a, const StudentNameGrade& b)
{
    // grathers comes first
    return a.grade > b.grade;
}


int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Words of encouragement" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Congratulations on reaching the end of the longest chapter in the tutorials! Unless you have previous programming 
    experience, this chapter was probably the most challenging one so far. If you made it this far, you’re doing great!

    The good news is that the next chapter is easy in comparison. And in the chapter beyond that, we reach the heart 
    of the tutorials: Object-oriented programming!
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Chapter summary" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Arrays allow us to store and access many variables of the same type through a single identifier. Array elements can be 
    accessed using the subscript operator ([]). Be careful not to index an array out of the array’s range. Arrays can be 
    initialized using an initializer list or uniform initialization.

    Fixed arrays must have a length that is set at compile time. Fixed arrays will usually decay into a pointer when evaluated 
    or passed to a function.

    Loops can be used to iterate through an array. Beware of off-by-one errors, so you don’t iterate off the end of your array. 
    Range-based for-loops are useful when the array hasn’t decayed into a pointer.

    Arrays can be made multidimensional by using multiple indices.

    Arrays can be used to do C-style strings. You should generally avoid these and use std::string_view and std::string instead.

    Pointers are variables that store the memory address of (point at) another variable. The address-of operator (&) can be used 
    to get the address of a variable. The indirection operator (*) can be used to get the value that a pointer points at.

    A null pointer is a pointer that is not pointing at anything. Pointers can be made null by initializing or assigning the 
    value nullptr to them. Avoid the NULL macro. Indirection through a null pointer can cause bad things to happen. Deleting a 
    null pointer is okay (it doesn’t do anything).

    A pointer to an array doesn’t know how large the array it is pointing to is. This means sizeof() and range-based for-loops 
    won’t work.

    The new and delete operators can be used to dynamically allocate memory for a pointer variable or array. Although it’s 
    unlikely to happen, operator new can fail if the operating system runs out of memory. If you’re writing software for a 
    memory-limited system, make sure to check if new was successful.

    Make sure to use the array delete (delete[]) when deleting an array. Pointers pointing to deallocated memory are called 
    dangling pointers. Using the wrong delete, or indirection through a dangling pointer causes undefined behavior.

    Failing to delete dynamically allocated memory can result in memory leaks when the last pointer to that memory goes out of 
    scope.

    Normal variables are allocated from limited memory called the stack. Dynamically allocated variables are allocated from a 
    general pool of memory called the heap.

    A pointer to a const value treats the value it is pointing to as const.

    int value{ 5 };
    const int *ptr{ &value }; // this is okay, ptr is pointing to a "const int"

    A const pointer is a pointer whose value can not be changed after initialization.

    int value{ 5 };
    int *const ptr{ &value }; // ptr is const, but *ptr is non-const

    A reference is an alias to another variable. References are declared using an ampersand (&), but this does not mean 
    address-of in this context. References are implicitly const -- they must be initialized with a value, and a new value can 
    not be assigned to them. References can be used to prevent copies from being made when passing data to or from a function.

    The member selection operator (->) can be used to select a member from a pointer to a struct. It combines both an indirection 
    and normal member access (.).

    Void pointers are pointers that can point to any type of data. Indirection through them is not possible directly. 
    You can use static_cast to convert them back to their original pointer type. It’s up to you to remember what type they 
    originally were.

    Pointers to pointers allow us to create a pointer that points to another pointer.

    std::array provides all of the functionality of C++ built-in arrays (and more) in a form that won’t decay into a pointer. 
    These should generally be preferred over built-in fixed arrays.

    std::vector provides dynamic array functionality, handles its own memory management and remembers its size. These should 
    generally be favored over built-in dynamic arrays.

    Thanks to iterators, we don’t have to know how a container is implemented to loop through its elements.

    The algorithms library helps us to save a lot of time by providing many off-the-shelf functions. In combination with 
    iterators (and later lambdas), the algorithms library is an important part of C++.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    To make the quizzes a little easier, we have to introduce a couple of new algorithms.

    std::reduce applies a function, by default the + operator, to all elements in a list, resulting in a single value. 
    When we use the + operator, the result is the sum of all elements in the list. Note that there’s also std::accumulate. 
    std::accumulate cannot be parallelized, because it applies the function left-to-right. std::reduce segments the list, 
    which means that the function is applied in an unknown order, allowing the operation to be parallelized. If we want to 
    sum up a list, we don’t care about the order and we use std::reduce.

    Author’s note

    std::reduce is currently not fully implemented in all major standard libraries. If it doesn’t work for you, fall back 
    to std::accumulate.

    std::shuffle takes a list and randomly re-orders its elements. We covered std::mt19937 in lesson 9.5 -- Random number 
    generation.
    */
    std::array arr{ 1, 2, 3, 4 };

    std::cout << std::reduce(arr.begin(), arr.end()) << '\n';

    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(arr.begin(), arr.end(), mt);

    for(auto& i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Question #1" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows. 
    Create an enum to identify the different types of items, and an std::array to store the number of each item the 
    player is carrying (The enumerators are used as indexes of the array). The player should start with 2 health potions, 
    5 torches, and 10 arrows. Write a function called countTotalItems() that returns how many items the player has in total. 
    Have your main() function print the output of countTotalItems() as well as the number of torches.
    */

    enum Items
    {
        health_potions,
        torches,
        arrows,
    };

    std::array arr_Q1{ 2, 5, 10 };

    std::cout << "Total number of items: " <<  countTotalItems(arr_Q1) << ". Number of torches: " << arr_Q1[Items::torches] << std::endl << '\n';


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Question #2" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////
    /*
     Write the following program: Create a struct that holds a student’s first name and grade (on a scale of 0-100). 
     Ask the user how many students they want to enter. Create a std::vector to hold all of the students. Then prompt 
     the user for each name and grade. Once the user has entered all the names and grade pairs, sort the list by grade 
     (highest first). Then print all the names and grades in sorted order.

    For the following input:

    Joe
    82
    Terry
    73
    Ralph
    4
    Alex
    94
    Mark
    88

    The output should look like this:

    Alex got a grade of 94
    Mark got a grade of 88
    Joe got a grade of 82
    Terry got a grade of 73
    Ralph got a grade of 4

    You can assume that names don’t contain spaces and that that input extraction doesn’t fail.
    */

    std::cout << "How many students you would like to enter? ";
    std::size_t num_of_students{};
    std::cin >> num_of_students;

    std::vector<StudentNameGrade> dynamic_array{ num_of_students };

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(int i{ 0 }; i != num_of_students; ++i)
    {
        std::cout << "Enter #" << (i+1) << ": ";
        std::cin >> dynamic_array[i].name;
        std::cin >> dynamic_array[i].grade; 
    }

    std::sort(dynamic_array.begin(), dynamic_array.end(), my_sort);

    for(int i{ 0 }; i != num_of_students; ++i)
    {
        std::cout << dynamic_array[i].name << " got a grade of "  << dynamic_array[i].grade << '\n';
    }




    return 0;
}

int countTotalItems(const std::array<int, 3>& arr)
{
    return ( std::reduce(arr.begin(), arr.end() ) );
}