#include <iostream>
#include <vector>
#include <string>
#include <limits>//for: std::cin.ignore
#include <iomanip> // for ws
#include <utility> // for swap
#include <algorithm> // for sort

int main()
{
    std::cout << "How many names you wish to create ?";
    int number_of_names{};
    std::cin >> number_of_names;

    std::vector<std::string> string_array(number_of_names);

    for(int count{ 0 }; count != number_of_names; ++count)
    {
        std::cout << "Enter name #" << (count+1) << ": ";
        std::getline( std::cin >> std::ws, string_array[count] );
    }
    
    std::sort(string_array.begin(), string_array.end());
    std::cout << std::endl;

    std::cout << "Here is your sorted list: \n";
    for(int count{ 0 }; count != number_of_names; ++count)
    {
        std::cout << "Name #" << (count+1) << ": ";
        std::cout << string_array[count] << '\n';
    }
    std::cout << std::endl;

    return 0;
}