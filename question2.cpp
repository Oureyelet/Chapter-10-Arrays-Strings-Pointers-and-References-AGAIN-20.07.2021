#include <iostream>
#include <string>
#include <iomanip> //for std::ws
#include <algorithm> // for std::sort
#include <limits> // for std::numeric_limits
#include <string_view>
#include <cctype> // lower and uper cases
#include <cstring>

int howMany()
{
    std::cout << "How many names would you like to enter? ";
    int how_many{};
    std::cin >> how_many;

    return how_many;
}

// Asks user to enter all the names
void enterNames(std::string* names, int lenght)
{
    // Ignore the line feed that was left by std::cin.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(int count{ 0 }; count != lenght; ++count)
    {
        std::cout << "Enter name #" << (count+1) << ": ";
        std::getline( std::cin >> std::ws, names[count] );
    }
}

// Prints the sorted names
void printNames(std::string* names, int lenght)
{
    std::cout << std::endl;
    std::cout << "Here is your sorted list: \n";

    for(int count{ 0 }; count != lenght; ++count)
    {
        std::cout << "Name #" << (count+1) << ": " << names[count] << '\n';
    }
}

int main()
{
    /*
    int lenght{ howMany() };

    // Allocate an array to hold the names
    auto* names{ new std::string[lenght]{} };

    enterNames(names, lenght);

    // Sort the array
    std::sort(names, names + lenght);

    printNames(names, lenght);

    delete[] names;
    */

    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //char text{};
    //std::string_view next{ "This is next string " };
    //std::getline( std::cin >> std::ws, str );

    //std::cout << str << text << next << '\n';

    //std::transform(str.begin(), str.end(), str.begin(), toupper);

    //std::cout << str << '\n';
    char str[]{ "Helloo" };

    
    std::tolower(str[0]);
    std::cout << "We changed it..." << str[0] <<  '\n';
    




    return 0;
}