#include <iostream>
#include <iterator> // for std::size

int main()
{
    std::cout << "Hello World" << "\n";

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "introduction" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Consider the case where we want to find the average test score of a class of students. 
    Using individual variables:
    */
    int numStudents{ 5 };

    int score0{ 84 };
    int score1{ 92 };
    int score2{ 76 };
    int score3{ 81 };
    int score4{ 56 };

    int totalScores{ score0 + score1 + score2 + score3 + score4 };
    auto averageScore{ static_cast<double>(totalScores) / numStudents };

    std::cout << "Using individual variables: " << averageScore << "\n";

    /*
    Using arrays offers a slightly better solution:
    */
    int scores[]{ 84, 92, 76, 81, 56 };
    int numStudents_Array{ static_cast<int>(std::size(scores)) };
    int totalScores_Array{ scores[0] + scores[1] + scores[2] + scores[3] + scores[4] };
    auto averageScore_Array{ static_cast<double>(totalScores_Array) / numStudents_Array };

    std::cout << "Using an array: " <<  averageScore_Array << "\n";


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Loops and arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Here’s our example above using a for loop:
    */ 
    int scores_loop[]{ 84, 92, 76, 81, 56 };
    int numStudents_loop{ static_cast<int>(std::size(scores_loop)) };

    int totalScores_loop{ 0 };

    for(int count{ 0 }; count < numStudents_loop; ++count)
    {
        totalScores_loop = totalScores_loop + scores_loop[ count ];
        // or: totalScores_loop +=  scores_loop[ count ];
    }

    auto averageScore_loop{ static_cast<double>(totalScores_loop) / numStudents_loop };

    std::cout << "Using loop: " << averageScore_loop << "\n";


    /*
    Here’s an example of using a loop to search an array in 
    order to determine the best score in the class:
    */

    int scores_search[]{ 84, 92, 76, 81, 56, 456 };
    int numStudents_search{ static_cast<int>(std::size(scores_search)) };

    int search{ 0 };

    for(int count{ 0 }; count < numStudents_search; ++count)
    {
        if(scores_search[count] > search)
            search = scores_search[count];
    }

    std::cout << "The best score was " << search << '\n';


    return 0;
}