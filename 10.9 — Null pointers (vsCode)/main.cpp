#include <iostream>
#include <cstddef> // for NULL and for std::nullptr_t
#include "functions.h"

int main()
{
    std::cout << "Hello World\n";

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Introduction" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*

    Just like normal variables, pointers are not initialized when they are instantiated. Unless a value is assigned, a 
    pointer will point to some garbage address by default.

    Besides memory addresses, there is one additional value that a pointer can hold: a null value. A null value is a 
    special value that means the pointer is not pointing at anything. A pointer holding a null value is called a null pointer.

    In C++, we can assign a pointer a null value by initializing or assigning it the literal 0:
    */
    float* ptr{ 0 };// ptr is now a null pointer

    float* ptr2;// ptr2 is uninitialized
    ptr2 = 0; // ptr2 is now a null pointer


    /*
    Pointers convert to boolean false if they are null, and boolean true if they are non-null. Therefore, we can use a 
    conditional to test whether a pointer is null or not:
    */
    double* ptr_d{ 0 };

    if(ptr_d)
        std::cout << "ptr is pointing to a double value which is: " << '\n';
    else
        std::cout << "ptr is a null pointer." << '\n';
    /*
    Best practice

    Initialize your pointers to a null value if you’re not giving them another value.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Indirection through null pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    In the previous lesson, we noted that indirection through a garbage pointer would lead to undefined results. 
    Indirection through a null pointer also results in undefined behavior. In most cases, it will crash your application.

    Conceptually, this makes sense. Indirection through a pointer means “go to the address the pointer is pointing at 
    and access the value there”. A null pointer doesn’t have an address. So when you try to access the value at that 
    address, what should it do?
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "The NULL macro" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    In C++, there is a special preprocessor macro called NULL (defined in the <cstddef> header). 
    This macro was inherited from C, where it is commonly used to indicate a null pointer.
    */
    double* pointer_double{ NULL };// ptr is a null pointer
    /*
    The value of NULL is implementation defined, but is usually defined as the integer constant 0. Note: as of C++11, 
    NULL can be defined as nullptr instead (which we’ll discuss in a bit).

    Best practice:

    Because NULL is a preprocessor macro with an implementation defined value, avoid using NULL.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "The perils of using 0 (or NULL) for null pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Note that the value of 0 isn’t a pointer type, so assigning 0 (or NULL, pre-C++11) to a pointer to denote that the pointer 
    is a null pointer is a little inconsistent. In rare cases, when used as a literal argument, it can even cause problems 
    because the compiler can’t tell whether we mean a null pointer or the integer 0:
    */
    int* x{ NULL };

    print(x);// calls print(int*) because x has type int*
    print(0);// calls print(int) because 0 is an integer literal
    print( nullptr );// likely calls print(int), although we probably wanted print(int*)


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "nullptr in C++11" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Best practice

    Use nullptr to initialize your pointers to a null value.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "std::nullptr_t" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    C++11 also introduces a new type called std::nullptr_t (in header <cstddef>). std::nullptr_t can only hold one value: 
    nullptr! While this may seem kind of silly, it’s useful in one situation. If we want to write a function that accepts 
    only a nullptr argument, what type do we make the parameter? The answer is std::nullptr_t.
    */
    doSomething(nullptr);// call doSomething with an argument of type std::nullptr_t
    //You probably won’t ever need to use this, but it’s good to know, just in case :)

    return 0;

}