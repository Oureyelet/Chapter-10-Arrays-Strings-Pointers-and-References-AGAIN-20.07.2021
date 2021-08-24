#include <iostream>

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
    In lesson 1.3 -- a first look at variables, we noted that a variable is a name for a piece of memory 
    that holds a value. When our program instantiates a variable, a free memory address is automatically assigned 
    to the variable, and any value we assign to the variable is stored in this memory address.
    
    For example:
    */
    int x{};

    /*
    When this statement is executed by the CPU, a piece of memory from RAM will be set aside. For the sake of 
    example, let’s say that the variable x is assigned memory location 140. Whenever the program sees the 
    variable x in an expression or statement, it knows that it should look in memory location 140 to get the value.

    The nice thing about variables is that we don’t need to worry about what specific memory address is 
    assigned. We just refer to the variable by its given identifier, and the compiler translates this name 
    into the appropriately assigned memory address.

    However, this approach has some limitations, which we’ll discuss in this and future lessons.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "The address-of operator (&)" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    The address-of operator (&) allows us to see what memory address is assigned to a variable. 
    This is pretty straightforward:
    */
    int y{ 5 };
    std::cout << y << '\n';// print the value of variable x
    std::cout << &y << '\n';// print the memory address of variable x


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "The indirection operator (*)" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Getting the address of a variable isn’t very useful by itself.

    The indirection operator (*) (also called dereference operator) allows us to access the value at a 
    particular address:
    */
    int z{ 5 };
    std::cout << z << '\n';// print the value of variable z
    std::cout << &z << '\n';// print the memory address of variable z
    std::cout << *(&z) << '\n';// print the value at the memory address of variable z (parenthesis not required, but make it easier to read)


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    With the address-of operator and indirection operators now added to our toolkits, we can now talk about pointers. 
    A pointer is a variable that holds a memory address as its value.

    Pointers are typically seen as one of the most confusing parts of the C++ language, but they’re surprisingly 
    simple when explained properly.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Declaring a pointer" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Pointer variables are declared just like normal variables, only with an asterisk between the data type 
    and the variable name. Note that this asterisk is not an indirection. It is part of 
    the pointer declaration syntax.
    */
    int* iPtr{}; // a pointer to an integer value
    double* dPtr{};// a pointer to a double value

    /*
    Best practice

    When declaring a pointer variable, put the asterisk next to the type to make it easier to distinguish 
    it from an indirection.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Assigning a value to a pointer" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    */



    return 0;
}