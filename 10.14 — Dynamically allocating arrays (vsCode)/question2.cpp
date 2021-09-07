#include <iostream>
#include <string> // std::getline
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

    // Ignore the line feed that was left by std::cin.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return how_many;
}

// Asks user to enter all the names
void enterNames(std::string* names, int lenght)
{
    for(int count{ 0 }; count != lenght; ++count)
    {
        std::cout << "Enter name #" << (count+1) << ": ";
        std::getline( std::cin >> std::ws, names[count] );

        if(islower(names[count][0]))
        {
            names[count][0] = toupper(names[count][0]);
        }
        for(int i{ 0 }; i < names[count].size(); ++i)
        {
            if( isspace(names[count][i-1]))
            {
                names[count][i] = toupper(names[count][i]);
            } 
        }
    }
}

// Prints the sorted names
void printNames(std::string* names, int lenght)
{
    std::cout << std::endl;
    std::cout << "Here is your sorted list: \n";

    for(int count{ 0 }; count != lenght; ++count)
    {
        std::cout << "Name #" << (count+1) << ": ";

        //if(names[count].length() == 3)
        //{

            
            for(int i{ static_cast<int>(names[count].length()) }; i >= 0; --i)
            {
                std::cout << names[count][i];
            }

            std::cout << '\n';
        //}
    }
}

int main()
{
    
    int lenght{ howMany() };

    // Allocate an array to hold the names
    auto* names{ new std::string[lenght]{} };

    enterNames(names, lenght);

    // Sort the array
    std::sort(names, names + lenght);

    printNames(names, lenght);

    delete[] names;
    


    
    




    return 0;
}