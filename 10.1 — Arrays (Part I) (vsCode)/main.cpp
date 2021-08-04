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
    
     
    

    return 0;
}