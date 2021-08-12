#include <iostream>
#include <utility> // for swap
#include <iterator> // for size
#include <string>
#include <algorithm> // for sort

int main()
{
    std::cout << "Hello World" << "\n";

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "A case for sorting" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "How sorting works" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Sorting is generally performed by repeatedly comparing pairs of array elements, and swapping 
    them if they meet some predefined criteria. The order in which these elements are compared 
    differs depending on which sorting algorithm is used. The criteria depends on how the list 
    will be sorted (e.g. in ascending or descending order).

    To swap two elements, we can use the std::swap() function from the C++ standard library, which 
    is defined in the utility header.
    */
    int x{ 7 };
    int y{ 3 };

    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    std::swap(x, y); // swap the values of x and y
    std::cout << "After swap:  x = " << x << ", y = " << y << '\n';


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Selection sort" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    There are many ways to sort an array. Selection sort is probably the easiest sort to understand, 
    which makes it a good candidate for teaching even though it is one of the slower sorts.
    */

    int array_swap[]{ 30, 50, 20, 4, 10, 40, 33, 2, 22 };
    constexpr int lenght{ static_cast<int>(std::size(array_swap)) };
    int start_index = array_swap[0];


    // Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
    for(int count{ 0 }; count < lenght-1; ++count)
    {
        if(array_swap[count] < start_index)
        {
            start_index = array_swap[count];
            std::swap(array_swap[count], start_index);
        }
    }
    std::cout << "smallest is: " << start_index << '\n';

   
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "std::sort" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Because sorting arrays is so common, the C++ standard library includes a sorting function 
    named std::sort. std::sort lives in the <algorithm> header, and can be invoked on an array like so:
    */
    std::string array_sort[]{"Mateusz", "Tobiasz", "Ania", "Klara", "BOcian"};
    constexpr int lenght_sort{ static_cast<int>(std::size(array_sort)) };

    std::sort(std::begin(array_sort), std::end(array_sort));
    

    for(int count{ 0 }; count < lenght_sort; ++count)
    {
        std::cout << array_sort[count] << ' ';
    }
    std::cout << std::endl;


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Question #1

    Manually show how selection sort works on the following array: { 30, 60, 20, 50, 40, 10 }. 
    Show the array after each swap that takes place. 

    Answer:
    { 30, 60, 20, 50, 40, 10 }
    { 10, 60, 20, 50, 40, 30 }
    { 10, 20, 60, 50, 40, 30 }
    { 10, 20, 30, 50, 40, 60 }
    { 10, 20, 30, 40, 50, 60 }
    { 10, 20, 30, 40, 50, 60 }
    */

    /*
    Question #2

    Rewrite the selection sort code above to sort in descending order (largest numbers first). 
    Although this may seem complex, it is actually surprisingly simple. 
    */

    int array_question2[]{ 30, 50, 20, 10, 40 };

    std::sort(std::begin(array_question2), std::end(array_question2));

    for(int count{static_cast<int>(std::size(array_question2))-1}; count > (-1); --count)
    {
        std::cout << array_question2[count] << ' ';
    }
    std::cout << std::endl;
 

    /*
    Question #3

    This one is going to be difficult, so put your game face on.

    Another simple sort is called “bubble sort”. Bubble sort works by comparing adjacent 
    pairs of elements, and swapping them if the criteria is met, so that elements “bubble” 
    to the end of the array. Although there are quite a few ways to optimize bubble sort, 
    in this quiz we’ll stick with the unoptimized version here because it’s simplest.

    Unoptimized bubble sort performs the following steps to sort an array from smallest to largest:
    A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.
    B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the 
    end of the array. At this point, the last element in the array will be sorted.
    C) Repeat the first two steps again until the array is sorted.

    Write code that bubble sorts the following array according to the rules above:
	
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    Print the sorted array elements at the end of your program.

    Hint: If we’re able to sort one element per iteration, that means we’ll need to iterate roughly 
    as many times as there are numbers in our array to guarantee that the whole array is sorted.
    Hint: When comparing pairs of elements, be careful of your array’s range.
    */
    int array_Question3[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    for(int count{})

    return 0;
}