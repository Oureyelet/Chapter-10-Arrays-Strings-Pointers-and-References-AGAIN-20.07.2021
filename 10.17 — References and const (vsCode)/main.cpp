#include <iostream>

// A function prototypes:
void someFCN();
void changeN(const int& ref);
void printIt(const int& x);


struct ArrayView
{
    const int* apples{};
    std::size_t lenght{};
};
ArrayView array;

void fn(const ArrayView& array)
{
    for(std::size_t i{ 0 }; i != array.lenght; ++i)
    {
        std::cout << array.apples[i] << ' ';
    }
}

int main()
{
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Reference to const value" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Just like it’s possible to declare a pointer to a const value, it’s also possible to declare a reference to a 
    const value. This is done by declaring a reference using the const keyword.
    */
    const int value_a{ 5 };
    const int& ref_value_a{ value_a };// ref is a reference to a const value

    /*
    A reference to a const value is often called a const reference for short, though this does make for some 
    inconsistent nomenclature with pointers.
    */

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing references to const values" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Unlike references to non-const values, which can only be initialized with non-const l-values, references to const 
    values can be initialized with non-const l-values, const l-values, and r-values.
    */
    int x{ 5 };
    const int& ref_x{ x };// okay, x is a non-const l-value

    const int y{ 7 };
    const int& ref_y{ y };// okay, y is a const l-value

    const int& ref_z{ 8 };// okay, 8 is an r-value

    /*
    Much like a pointer to a const value, a reference to a const value can reference a non-const variable. 
    When accessed through a reference to a const value, the value is considered const even if the original variable is not:
    */
    int apple{ 5 };
    const int& ref_apple{ apple };// create const reference to variable apples

    apple = 22;// okay, apples is non-const
    //ref_apple = 7;// illegal -- ref is const


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "References to r-values extend the lifetime of the referenced value" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Normally r-values have expression scope, meaning the values are destroyed at the end of the 
    expression in which they are created.
    */
    std::cout << 2 + 3 << '\n'; // 2 + 3 evaluates to r-value 5, which is destroyed at the end of this statement

    /*
    However, when a reference to a const value is initialized with an r-value, the lifetime of the r-value is 
    extended to match the lifetime of the reference.
    */
    someFCN();


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const references as function parameters" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    References used as function parameters can also be const. This allows us to access the argument without making a 
    copy of it, while guaranteeing that the function will not change the value being referenced.
    */
    changeN(apple);

    /*
    References to const values are particularly useful as function parameters because of their versatility. 
    A const reference parameter allows you to pass in a non-const l-value argument, a const l-value argument, a literal, 
    or the result of an expression:
    */
    int a{ 1 };
    printIt( a ); // non-const l-value

    const int b{ 2 };
    printIt( b );// const l-value

    printIt( 3 );// literal r-value

    printIt( 2 + b );// expression r-value

    /*
    To avoid making unnecessary, potentially expensive copies, variables that are not pointers or fundamental data types 
    (int, double, etc…) should be generally passed by (const) reference. Fundamental data types should be passed by value, 
    unless the function needs to change them. There are a few exceptions to this rule, namely types that are so small that 
    it’s faster for the CPU to copy them than having to perform an extra indirection for a reference.

    A reminder:
    References act like pointers. The compiler adds the indirection, which we’d do manually on a pointer using an asterisk, 
    for us.

    One of those fast types is std::string_view. You’ll learn about more exceptions later. If you’re uncertain if a 
    non-fundamental type is fast to pass by value, pass it by const reference.

    Best practice:
    Pass non-pointer, non-fundamental data type variables (such as structs) by (const) reference, unless you know that 
    passing it by value is faster. 
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Question #1

    Which of the following types should be passed by value, which by const reference? You can assume the function that 
    takes these types as parameters doesn’t modify them.
    */
   
    int array[3]{};

    fn({ array, std::size(array) });






   return 0;
}

void someFCN()
{
    const int& ref{ 2 + 3 };// normally the result of 2+3 has expression scope and is 
    //destroyed at the end of this statement
    // but because the result is now bound to a reference to a const value...
    std::cout << ref << '\n';
}// and the lifetime of the r-value is extended to here, when the const reference dies

// ref is a const reference to the argument passed in, not a copy
void changeN(const int& ref)
{
    //ref = 123;// not allowed, ref is const
}

void printIt(const int& x)
{
    std::cout << x << '\n';
}