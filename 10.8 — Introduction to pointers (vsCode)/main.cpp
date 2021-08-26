#include <iostream>
#include <typeinfo> // for: typeid(x).name()

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
    Since pointers only hold addresses, when we assign a value to a pointer, that value has to be an address. 
    One of the most common things to do with pointers is have them hold the address of a different variable.

    To get the address of a variable, we use the address-of operator:
    */
    int v{ 5 };
    int* ptr_V{ &v };// initialize ptr_V with address of variable v

    std::cout << &v << '\n';// print the address of variable v
    std::cout << ptr_V << '\n'; // print the address that ptr is holding

    //The type of the pointer has to match the type of the variable being pointed to: ! ! ! ! !
    int iValue{ 7 };
    double dValue{ 77 };

    int* ptr_iValue{ &iValue };// ok
    double* ptr_dValue{ &dValue }; // also ok

    std::cout << "dobuel adddress: " << ptr_iValue << '\n';
/*
    ptr_iValue = &dValue; // wrong -- int pointer cannot point to the address of a double variable
    ptr_dValue = &iValue; // wrong -- double pointer cannot point to the address of an int variable
*/
    //Note that the following is also not legal:
    //int* intiger{ 5 };
    /*
    This is because pointers can only hold addresses, and the integer literal 5 does not have a memory address. 
    If you try this, the compiler will tell you it cannot convert an integer to an integer pointer.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "The address-of operator returns a pointer" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////   
    /*
    It’s worth noting that the address-of operator (&) doesn’t return the address of its operand as a literal. 
    Instead, it returns a pointer containing the address of the operand, whose type is derived from the argument 
    (e.g. taking the address of an int will return the address in an int pointer).

    We can see this in the following example:
    */
    int x_return{ 7 };

    std::cout << typeid(&x_return).name() << '\n';


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Indirection through pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Once we have a pointer variable pointing at something, the other common thing to do with it is indirection 
    through the pointer to get the value of what it’s pointing at. Indirection through a pointer evaluates to the 
    contents of the address it is pointing to.
    */
    double y_double{ 33 };
    std::cout << y_double << '\n';// prints contents of value
    std::cout << &y_double << '\n';// prints address of value

    double* y_double_ptr{ &y_double };// ptr points to value
    std::cout << y_double_ptr << '\n';// prints address held in ptr, which is &y_double
    std::cout << *y_double_ptr << '\n';// Indirection through ptr (get the value that ptr is 


    /*
    This is why pointers must have a type. Without a type, when indirecting through a pointer, the pointer wouldn’t know 
    how to interpret the contents it was pointing to. It’s also why the type of the pointer and the variable address it’s 
    being assigned to must match. If they did not, indirection through the pointer would misinterpret the 
    bits as a different type.

    Once assigned, a pointer value can be reassigned to another value:
    */
    int value_1{ 333 };
    int value_2{ 777 };

    int* ptr_value{};

    ptr_value = &value_1;// ptr_value points to value_1
    std::cout << *ptr_value << std::endl; // prints 333

    ptr_value = &value_2;// ptr_value points to value_2
    std::cout << *ptr_value; // prints 777
    /*
    When the address of variable value is assigned to ptr, the following are true:

    - ptr is the same as &value
    - *ptr is treated the same as value
    */
    std::cout << std::endl;
    /*
    Because *ptr is treated the same as value, you can assign values to it just as if it were variable value! 
    The following program prints 7:
    */
    int value_3{ 100 };
    int* ptr_value_3{ &value_3 };

    std::cout << ptr_value_3 << '\n'; // print address
    std::cout << *ptr_value_3 << '\n'; // print value
    std::cout << &value_3 << '\n';// print again address

    *ptr_value_3 = 7; // *ptr_value_3 is the same as value, which is assigned 7
    std::cout << value_3 << '\n'; // print 7


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "A warning about indirection through invalid pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////    
    /*
    https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "The size of pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    The size of a pointer is dependent upon the architecture the executable is compiled for -- a 32-bit executable uses 
    32-bit memory addresses -- consequently, a pointer on a 32-bit machine is 32 bits (4 bytes). With a 64-bit executable, 
    a pointer would be 64 bits (8 bytes). Note that this is true regardless of the size of the object being pointed to:
    */
    char* ptr_char{};// chars are 1 byte
    int* ptr_int{};// ints are usually 4 bytes

    struct Something
    {
        int x{};
        int y{};
        int z{};
    };

    Something* somethingPtr{};// Something is probably 24 bytes

    std::cout << sizeof(ptr_char) << '\n';// print 8
    std::cout << sizeof(ptr_int) << '\n';// print 8
    std::cout << sizeof(somethingPtr) << '\n';// print 8
    

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "What good are pointers?" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    At this point, pointers may seem a little silly, academic, or obtuse. Why use a pointer if we can just use the original 
    variable?

    It turns out that pointers are useful in many different cases:

    1) Arrays are implemented using pointers. Pointers can be used to iterate through an array 
    (as an alternative to array indices) (covered in lesson 10.24 -- Introduction to iterators).
    2) They are the only way you can dynamically allocate memory in C++ (covered in lesson 10.13 -- Dynamic memory allocation 
    with new and delete). This is by far the most common use case for pointers.
    3) They can be used to pass a function as a parameter to another function (covered in lesson 11.7 -- Function Pointers).
    4) They can be used to achieve polymorphism when dealing with inheritance (covered in lesson 18.1 -- Pointers and references 
    to the base class of derived objects).
    5) They can be used to have one struct/class point at another struct/class, to form a chain. This is useful in some more 
    advanced data structures, such as linked lists and trees.

    So there is actually a surprising number of uses for pointers. But don’t worry if you don’t understand what most of these 
    are yet. Now that you understand what pointers are at a basic level, we can start taking an in-depth look at the various 
    cases in which they’re useful, which we’ll do in subsequent lessons.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz Time" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Question #1
    What values does this program print? Assume a short is 2 bytes, and a 32-bit machine.
    */

        short value{ 7 }; // &value = 0012FF60
        short otherValue{ 3 }; // &otherValue = 0012FF54

        short* ptr{ &value };//0012FF60

        std::cout << &value << '\n'; // print address 0012FF60
        std::cout << value << '\n'; // print value 7
        std::cout << ptr << '\n'; //print address 0012FF60
        std::cout << *ptr << '\n'; //print value 7
        std::cout << '\n';

        *ptr = 9; // we changed short value for 9 now/

        std::cout << &value << '\n';// print address 0012FF60
        std::cout << value << '\n';// print value 9
        std::cout << ptr << '\n';//print address 0012FF60
        std::cout << *ptr  << '\n';// print value 9
        std::cout << '\n';

        ptr = &otherValue; // 0012FF54

        std::cout << &otherValue << '\n'; // print address 0012FF54
        std::cout << otherValue << '\n'; //print value 3
        std::cout << ptr << '\n';// print address 0012FF54
        std::cout << *ptr << '\n'; //print value 3
        std::cout << '\n';

        std::cout << sizeof(ptr) << '\n';
        std::cout << sizeof(*ptr) << '\n';


    /*
    Question #2
    What’s wrong with this snippet of code? 
    */
    short value_quiz{ 45 };

    short* ptr_quiz{ &value_quiz }; // declare a pointer and initialize with address of value
    //*ptr_quiz = &value_quiz; // assign address of value to ptr

    //my answer: when we assing "*ptr_quiz =" we should assaing with value not with address.
    //should be:
    ptr_quiz = &otherValue;
    //or:
    *ptr_quiz = 7;



    return 0;
}