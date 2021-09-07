#include <iostream>

int main()
{
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointing to const variables" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    So far, all of the pointers you’ve seen are non-const pointers to non-const values:
    */
    int value{ 55 };
    int* ptr_value{ &value };
    *ptr_value = 6; // change value to 6

    //However, what happens if value is const?
    const double double_value{ 3.75 };// double_value is const
    //double* ptr_double{ &double_value };// compile error: cannot convert const double* to double*
    //*ptr_double = 4.35;// change value to 4.35
    /*
    The above snippet won’t compile -- we can’t set a non-const pointer to a const variable. This makes sense: 
    a const variable is one whose value can not be changed. Hypothetically, if we could set a non-const pointer to 
    a const value, then we would be able perform indirection through the non-const pointer and change the value. 
    That would violate the intention of const.
    */

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointer to const value" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    A pointer to a const value is a (non-const) pointer that points to a constant value.

    To declare a pointer to a const value, use the const keyword before the data type:
    */
    const char tobiasz{ 'T' };
    const char* ptr_Tobiasz{ &tobiasz };// this is okay, ptr is a const pointer that is pointing to a "const int"
    //*ptr_Tobiasz = "Hello"; // not allowed, we can't change a const value
    
    /*
    In the above example, ptr_Tobiasz points to a const char.

    So far, so good, right? Now consider the following example:
    */
    int value_int{ 33 };// value is not constant
    const int* ptr_value_int{ &value_int };// this is still okay
    /*
    A pointer to a constant variable can point to a non-constant variable (such as variable value in the example above). 
    Think of it this way: a pointer to a constant variable treats the variable as constant when it is accessed through the 
    pointer, regardless of whether the variable was initially defined as const or not.
    */

    //Thus, the following is okay:
    int value_one{ 1 };
    const int* ptr_value_one{ &value_one };// ptr_value_one points to a "const int"
    value_one = 33;// the value_one is non-const when accessed through a non-const identifier

    //But the following is not:
    int value_one_1{ 1 };
    const int* ptr_value_one_1{ &value_one_1 };// ptr_value_one_1 points to a "const int"
    //*ptr_value_one_1 = 33;// ptr_value_one_1 treats its value_one_1 as const, so changing the value_one_1 through ptr_value_one_1 is not legal

    /*
    Because a pointer to a const value is not const itself (it just points to a const value), the pointer can be redirected 
    to point at other values:
    */
    int v_1{ 3 };
    const int* ptr_v_1{ &v_1 };// ptr points to a const int

    int v_2{ 7 };
    ptr_v_1 = &v_1;// okay, ptr now points at some other const int


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Const pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    We can also make a pointer itself constant. A const pointer is a pointer whose value can not be 
    changed after initialization

    To declare a const pointer, use the const keyword between the asterisk and the pointer name:
    */
    int v_3{ 77 };
    int* const ptr_v_3{ &v_3 };
    /*
    Just like a normal const variable, a const pointer must be initialized to a value upon declaration. 
    This means a const pointer will always point to the same address. In the above case, ptr will always point to the 
    address of value (until ptr goes out of scope and is destroyed).
    */

    int p_1{ 5 };
    int p_2{ 6 };

    int* const ptr_p_1{ &p_1 };// okay, the const pointer is initialized to the address of value1
    //ptr_p_1 = &p_2// not okay, once initialized, a const pointer can not be changed.

    /*
    However, because the value being pointed to is still non-const, it is possible to change the value being pointed 
    to indrectly through the const pointer:
    */

    int f_1{ 27 };
    int* const ptr_f_1{ &f_1 }; // ptr will always point to value
    *ptr_f_1 = 28;// allowed, since ptr points to a non-const int


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Const pointer to a const value" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Finally, it is possible to declare a const pointer to a const value by using the const keyword both before 
    the type and before the variable name:
    */
    int g_22{ 22 };
    const int* const ptr_g_22{ &g_22 };
    /*
    A const pointer to a const value can not be set to point to another address, nor can the value 
    it is pointing to be changed through the pointer.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Recapping" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    To summarize, you only need to remember 4 rules, and they are pretty logical:

    1. A non-const pointer can be redirected to point to other addresses.
    2. A const pointer always points to the same address, and this address can not be changed. 

    3. A pointer to a non-const value can change the value it is pointing to. These can not point to a const value.
    4. A pointer to a const value treats the value as const (even if it is not), and thus can not change the value it 
    is pointing to. 

    Keeping the declaration syntax straight can be challenging. Just remember that the type of value the pointer points 
    to is always on the far left:
    */
    int c_13{ 13 };
    const int* ptr_c_13_A{ &c_13 }; // ptr1 points to a "const int", so this is a pointer to a const value.
    int* const ptr_c_13_B{ &c_13 }; // ptr2 points to an "int", so this is a const pointer to a non-const value.
    const int* const ptr_c_13_C{ &c_13 }; // ptr3 points to a "const int", so this is a const pointer to a const value.

    /*
    Pointers to const values are primarily used in function parameters (for example, when passing an array to a function) 
    to help ensure the function doesn’t inadvertently change the passed in argument. We will discuss this further in the 
    section on functions.
    */











    return 0;
}