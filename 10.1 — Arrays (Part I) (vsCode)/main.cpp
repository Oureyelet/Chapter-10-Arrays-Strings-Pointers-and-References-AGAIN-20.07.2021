#include <iostream>

int main()
{
    std::cout << "Hello World" << '\n';

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Arrays (Part I)" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Consider the case where you want to record the test scores for 30 students in a class:
    */
    // allocate 30 integer variables (each with a different name)
    int testScoreStudent1{};
    int testScoreStudent2{};
    int testScoreStudent3{};

    //...

    int testScoreStudent30{};

    /*
    Arrays give us a much easier way to do this. 
    The following array definition is essentially equivalent:
    */
    int testScoreStudent[30]{};// allocate 30 integer variables in a fixed array.

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Array elements and subscripting" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "An example array program" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Here’s a sample program that puts together the definition and indexing of an array:
    */
    int prime[5]{};// hold the first 5 prime numbers

    prime[0] = 2;// The first element has index 0
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11;// The last element has index 4 (array length-1)

    std::cout << "The lowest prime number is: " << prime[0] << '\n';
    std::cout << "The sum of the first 5 primes is: " << prime[0] + prime[1] + prime[2] +prime[3] +
    prime[4] << '\n';


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Array data types" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Arrays can be made from any data type. Consider the following example, where we declare 
    an array of doubles:
    */
    double batteryLifeInHours[3]{};// allocate 3 doubles

    batteryLifeInHours[0] = 2.0;
    batteryLifeInHours[1] = 3.0;
    batteryLifeInHours[2] = 4.3;

    std::cout << "The average battery life is " << (batteryLifeInHours[0] + 
    batteryLifeInHours[1] + batteryLifeInHours[2]) / 3.0 << " hour(s)\n";


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Arrays and structs" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Arrays can also be made from structs. Consider the following example:
    */
    struct Rectangle
    {
        int lenght{};
        int width{};
    };

    Rectangle rects[5]{};// declare an array of 5 Rectangle

    /*
    To access a struct member of an array element, first pick which array element you want, 
    and then use the member selection operator to select the struct member you want:
    */
    rects[0].lenght = 24;
    rects[0].width = 15;

    std::cout << "circumference of our rectangle is " << 2 * (rects[0].lenght + rects[0].width) << '\n';


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Array subscripts" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    In C++, array subscripts must always be an integral type
    Here are some examples:
    */
    int array[5]{};// declare an array of length 5

    // using a literal (constant) index:
    array[0] = 7; // ok

    // using an enum (constant) index:
    enum Animals
    {
        animal_cat = 2
    };
    array[Animals::animal_cat] = 4; // ok

    // using a variable (non-constant) index:
    short index = 3;
    array[index] = 7; // ok

    // using an expression that evaluates to an integer index:
    array[1+3] = 7; // ok

    
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Fixed array declarations" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////

    // using a literal constant:
    int numberOfLessonsPerDay[7]{}; //ok

    // using a constexpr symbolic constant:
    constexpr int daysPerWeek{ 7 };
    int numberOfLessonsPerDay[daysPerWeek]{}; //ok

    // using an enumerator
    enum Weekend
    {
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday,

        maxWeekDay
    };
    int numberOfLessonsPerDay[Weekend::maxWeekDay]{}; // ok


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "A note on dynamic arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    




    

    return 0;
}