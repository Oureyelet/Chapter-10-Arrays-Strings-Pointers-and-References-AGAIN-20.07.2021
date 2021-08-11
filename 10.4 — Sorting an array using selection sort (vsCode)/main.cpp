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
    std::string array_sort[]{"Mateusz", "Tobiasz", "Ania", "Klara"};
    constexpr int lenght_sort{ static_cast<int>(std::size(array_sort)) };

    std::sort(std::begin(array_sort), std::end(array_sort));
    

    for(int count{ 0 }; count < lenght_sort; ++count)
    {
        std::cout << array_sort[count] << ' ';
    }
    std::cout << std::endl;


    return 0;
}