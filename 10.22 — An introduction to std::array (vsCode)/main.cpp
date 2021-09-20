#include <iostream>
#include <array> // for std::array
#include <algorithm> //for std::sort

void printLenght(const std::array<double, 5>& myArray)
{
    std::cout << "Lenght: " << myArray.size() << '\n';
}

// printArray2 is a template function
template<typename T, std::size_t size>// parameterize the element type and size
void printArray2(const std::array<T, size>& myArray)
{
    for(auto element : myArray)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "An introduction to std::array" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    In previous lessons, we’ve talked at length about fixed and dynamic arrays. Although both are built right into the 
    C++ language, they both have downsides: Fixed arrays decay into pointers, losing the array length information when they 
    do, and dynamic arrays have messy deallocation issues and are challenging to resize without error.

    To address these issues, the C++ standard library includes functionality that makes array management easier, std::array 
    and std::vector. We’ll examine std::array in this lesson, and std::vector in the next.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "An introduction to std::array" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    std::array provides fixed array functionality that won’t decay when passed into a function. 
    std::array is defined in the <array> header, inside the std namespace.

    Declaring a std::array variable is easy:
    */
    std::array<int, 3> myArray; // declare an integer array with length 3

    /*
    Just like the native implementation of fixed arrays, the length of a std::array must be known at compile time.

    std::array can be initialized using initializer lists or list initialization:
    */
    std::array<int, 5> myArray2 = { 9, 7, 5, 3, 1 };// initializer list
    std::array<int, 5> myArray3{ 9, 7, 5, 3, 1 };// list initialization

    //Unlike built-in fixed arrays, with std::array you can not omit the array length when providing an initializer.

    /*
    However, since C++17, it is allowed to omit the type and size. They can only be omitted together, but not one or the 
    other, and only if the array is explicitly initialized.
    */
    std::array myArray4{ 9, 7, 5, 3, 1 };// The type is deduced to std::array<int, 5>
    std::array myArray5{ 9.7, 7.31 };// The type is deduced to std::array<double, 2>    

    /*
    We favor this syntax rather than typing out the type and size at the declaration. 
    If your compiler is not C++17 capable, you need to use the explicit syntax instead.
    */
    //std::array myArray{ 9, 7, 5, 3, 1 };// Since C++17
    std::array<int, 5> myArray6{ 9, 7, 5, 3, 1 };// Before C++17

    //std::array myArray{ 9.7, 7.31 };// Since C++17
    std::array<double, 2> myArray7{ 9.7, 7.31 };// Before C++17

    /*
    Since C++20, it is possible to specify the element type but omit the array length. This makes creation of std::array a 
    little more like creation of C-style arrays. To create an array with a specific type and deduced size, we use the 
    std::to_array function:
    */
    //auto myArray11 { std::to_array<int, 5>({ 9, 7, 5, 3, 1 }) }; // Specify type and size
    //auto myArray22 { std::to_array<int>({ 9, 7, 5, 3, 1 }) }; // Specify type only, deduce size
    //auto myArray33 { std::to_array({ 9, 7, 5, 3, 1 }) }; // Deduce type and size

    /*
    Unfortunately, std::to_array is more expensive than creating a std::array directly, because it actually copies all 
    elements from a C-style array to a std::array. For this reason, std::to_array should be avoided when the array is 
    created many times (e.g. in a loop).

    You can also assign values to the array using an initializer list
    */
    std::array<int, 5> myArray34;
    myArray34 = { 0, 1, 2, 3, 4 }; // okay
    myArray34 = { 9, 8, 7 }; // okay, elements 3 and 4 are set to zero!
    //myArray34 = { 0, 1, 2, 3, 4, 5 }; // not allowed, too many elements in initializer list!

    //Accessing std::array values using the subscript operator works just like you would expect:
    std::cout << myArray34[1] << '\n';
    myArray34[2] = 6;

    /*
    Just like built-in fixed arrays, the subscript operator does not do any bounds-checking. If an invalid index is provided, 
    bad things will probably happen.

    std::array supports a second form of array element access (the at() function) that does bounds checking:
    */
    std::array myArray9{ 9, 7, 5, 3, 1 };
    myArray9.at(1) = 8;// array element 1 is valid, sets array element 1 to value 8;

    /*
    In the above example, the call to myArray.at(1) checks to ensure the index 1 is valid, and because it is, it returns a 
    reference to array element 1. We then assign the value of 6 to this. However, the call to myArray.at(9) fails because 
    array element 9 is out of bounds for the array. Instead of returning a reference, the at() function throws an error that 
    terminates the program (note: It’s actually throwing an exception of type std::out_of_range -- we cover exceptions 
    in chapter 14). Because it does bounds checking, at() is slower (but safer) than operator[].

    std::array will clean up after itself when it goes out of scope, so there’s no need to do any kind of manual cleanup.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Size and sorting" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    The size() function can be used to retrieve the length of the std::array:
    */
    std::array myArray10{ 9.0, 7.2, 5.4, 3.6, 1.8 };
    std::cout << "lenght: " << myArray10.size() << '\n';
    
    /*
    Because std::array doesn’t decay to a pointer when passed to a function, the size() function will work even if 
    you call it from within a function:
    */
    printLenght(myArray10);

    /*
    Note that the standard library uses the term “size” to mean the array length — do not get this confused with the 
    results of sizeof() on a native fixed array, which returns the actual size of the array in memory (the size of an 
    element multiplied by the array length). Yes, this nomenclature is inconsistent.

    Also note that we passed std::array by (const) reference. This is to prevent the compiler from making a copy of the 
    std::array when the std::array was passed to the function (for performance reasons).

    Best practice:
    Always pass std::array by reference or const reference

    Because the length is always known, range-based for-loops work with std::array:
    */
    std::array myArray12{ 9, 7, 5, 3, 1 };

    for(auto element : myArray12)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    //You can sort std::array using std::sort, which lives in the <algorithm> header:
    std::array myArray13{ 7, 3, 1, 9, 5 };

    std::sort(myArray13.begin(), myArray13.end());// sort the array forwards
    for(auto element : myArray13)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    std::sort(myArray13.rbegin(), myArray13.rend());// sort the array backwards
    for(auto element : myArray13)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    /*
    The sorting function uses iterators, which is a concept we haven’t covered yet, so for now you can treat the 
    parameters to std::sort() as a bit of magic. We’ll explain them later.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Passing std::array of different lengths to a function" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    With a std::array, the element type and array length are part of the type information. Therefore, when we use a 
    std::array as a function parameter, we have to specify the element type and array length.

    void printArray(const std::array<int, 5>& myArray)
    {
        for (auto element : myArray)
            std::cout << element << ' ';
        std::cout << '\n';
    }

    int main()
    {
        std::array myArray5{ 9.0, 7.2, 5.4, 3.6, 1.8 };
        printArray(myArray5);

        return 0;
    }
    */

    /*
    The downside is that this limits our function to only handling arrays of this specific type and length. But what if we 
    want to have our function handle arrays of different element types or lengths? We’d have to create a copy of the function 
    for each different element type and/or array length we want to use. That’s a lot of duplication.

    Fortunately, we can have C++ do this for us, using templates. We can create a template function that parameterizes part 
    or all of the type information, and then C++ will use that template to create “real” functions (with actual types) as needed.
    */
    std::array myArray14{ 9.0, 7.2, 5.4, 3.6, 1.8 };
    printArray2(myArray14);

    std::array myArray15{ 9.0, 7.2, 5.4, 3.6, 1.8, 1.2, 0.7 };
    printArray2(myArray15);

    /*
    Related content:

    We cover function templates in lesson 8.13 -- Function templates. 
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Manually indexing std::array via size_type" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Pop quiz: What’s wrong with the following code?
    
    #include <iostream>
    #include <array>

    int main()
    {
    std::array myArray { 7, 3, 1, 9, 5 };

    // Iterate through the array and print the value of the elements
    for (int i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
}

    */
    
    /*
    The answer is that there’s a likely signed/unsigned mismatch in this code! Due to a curious decision, the size() 
    function and array index parameter to operator[] use a type called size_type, which is defined by the C++ standard as 
    an unsigned integral type. Our loop counter/index (variable i) is a signed int. Therefore both the comparison 
    i < myArray.size() and the array index myArray[i] have type mismatches.

    Interestingly enough, size_type isn’t a global type (like int or std::size_t). Rather, it’s defined inside the 
    definition of std::array (C++ allows nested types). This means when we want to use size_type, we have to prefix it 
    with the full array type (think of std::array acting as a namespace in this regard). In our above example, 
    the fully-prefixed type of “size_type” is std::array<int, 5>::size_type!

    Therefore, the correct way to write the above code is as follows:
    for (std::array<int, 5>::size_type i{ 0 }; i < myArray.size(); ++i)

    That’s not very readable. Fortunately, std::array::size_type is just an alias for std::size_t, so we can use that instead.
    for (std::size_t i{ 0 }; i < myArray.size(); ++i)
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Array of struct" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Of course std::array isn’t limited to numbers as elements. Every type that can be used in a regular array can be used 
    in a std::array.
    */



    return 0;
}