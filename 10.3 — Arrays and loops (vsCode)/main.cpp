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


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Mixing loops and arrays" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Arrays and off-by-one errors" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    When using loops with arrays, always double-check your loop conditions to make 
    sure you do not introduce off-by-one errors.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz TIME ! :D" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Question #1
    Print the following array to the screen using a loop:
	
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    Hint: You can use std::size (as of C++17) or the sizeof() trick (prior to C++17) 
    to determine the array length.
    */
    constexpr int array_Quiz[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    constexpr int numArray_Quiz{ static_cast<int>(std::size(array_Quiz)) };

    for(int count{ 0 }; count < numArray_Quiz; ++count)
    {
        std::cout << array_Quiz[count] << ' ';
    }
    std::cout << std::endl;


    /*
    Question #2
    Given the array in question 1:

    Ask the user for a number between 1 and 9. If the user does not enter a number between 1 and 9, 
    repeatedly ask for an integer value until they do. Once they have entered a number between 1 and 9, 
    print the array. Then search the array for the value that the user entered and print 
    the index of that element.

    You can test std::cin for invalid input by using the following code:
	
    // if the user entered something invalid
    if (std::cin.fail())
    {
        std::cin.clear(); // reset any error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        // ignore any characters in the input buffer
    }
    */
    int user_choice{};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> user_choice;
        
        // if the user entered an invalid character
        if (std::cin.fail())
        {
        std::cin.clear(); // reset any error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        // ignore any characters in the input buffer
        }
        
    } while (user_choice < 1 || user_choice > 9);
    
    for(int count{ 0 }; count < numArray_Quiz; ++count)
    {
        std::cout << array_Quiz[count] << ' ';
    }
    std::cout << std::endl;

    for(int count{ 0 }; count < numArray_Quiz; ++count)
    {
        if(user_choice == array_Quiz[count])
        {
            std::cout << count << '\n';

            break;// since each # in the array is unique, no need to search rest of array
        }
    }
    std::cout << std::endl;
    
    
    /*
    Question #3

    Modify the following program so that instead of having maxScore hold the largest score directly, 
    a variable named maxIndex holds the index of the largest score. 
    */
    constexpr int scores_Quiz[]{ 84, 92, 767, 81, 56, 34 };
 
    int maxScore_Quiz{ 0 }; // Assume our largest score is 0 to start
    int maxIndex_Quiz{ 0 };
 
    // now look for a larger score in the full array
    for (int student_Quiz{ 0 }; student_Quiz < static_cast<int>(std::size(scores_Quiz)); ++student_Quiz)
    {
        if (scores_Quiz[student_Quiz] > maxScore_Quiz)
        {
            maxScore_Quiz = scores_Quiz[student_Quiz];
            maxIndex_Quiz = student_Quiz;
        }
    }
 
    std::cout << "The best score was " << maxScore_Quiz << '\n';
    std::cout << "Index of the largest score is " << maxIndex_Quiz << '\n';



    return 0;
}