#include <iostream>
#include <iterator> // std::size
#include <cstring> // std::strcpy, std::strlen(), 

int main()
{
    std::cout << "Hello World\n";

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Introduction" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Modern C++ supports two different types of strings: std::string (as part of the standard library), 
    and C-style strings (natively, as inherited from the C language). 
    */

    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "C-style strings" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    ~~~Null terminator is a special character (‘\0’, ascii code 0) 
    used to indicate the end of the string
    */

    //To define a C-style string, simply declare a char array and initialize it with a string literal:
    char myString[]{ "String" };
    /*
    Although “string” only has 6 letters, C++ automatically adds a null terminator to the 
    end of the string for us (we don’t need to include it ourselves). Consequently, myString is 
    actually an array of length 7!
    */
    const int length{ static_cast<int>(std::size(myString)) };
    
    std::cout << myString << " has " << length << " characters.\n";

    for(int index{ 0 }; index < length; ++index)
        std::cout << static_cast<int>(myString[index]) << ' ';

    std::cout << std::endl;

    /*
    Since C-style strings are arrays, you can use the [] operator to change individual 
    characters in the string:
    */
    myString[1] = 'p';
    std::cout << myString << '\n';

    
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "C-style strings and std::cin" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    There are many cases where we don’t know in advance how long our string is going to be. 
    For example, consider the problem of writing a program where we need to ask the user to enter 
    their name. How long is their name? We don’t know until they enter it!

    In this case, we can declare an array larger than we need:
    */
    char name[255]{};// declare array large enough to hold 254 characters + null terminator

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "You entered: " << name << '\n';

    // Ignore to the end of file ( This is clean our std::cin buffer )
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    //The recommended way of reading C-style strings using std::cin is as follows:
    char surname[255]{};
    std::cout << "Enter your surname: ";
    std::cin.getline(surname, std::size(surname));
    std::cout << "You entered: "<< surname << '\n';
    /*
    This call to cin.getline() will read up to 254 characters into name 
    (leaving room for the null terminator!). Any excess characters will be discarded. 
    In this way, we guarantee that we will not overflow the array!
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Manipulating C-style strings" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    C++ provides many functions to manipulate C-style strings as part of the <cstring> header. 
    Here are a few of the most useful:
    */

    /*
    strcpy() allows you to copy a string to another string. 
    More commonly, this is used to assign a value to a string:
    */
    char source[]{ "Copy this!" };
    char dest[50];// note that if the length of dest is only 5 chars this cause overflow results!
    std::strcpy(dest, source);
    std::cout << dest << '\n'; //print "Copy this!"

    /*
    Another useful function is the strlen() function, which returns the length of the C-style string 
    (without the null terminator).
    */
    char name_1[20]{ "Alex" }; // only use 5 characters (4 letters + null terminator)
    std::cout << "My name is: " << name_1  << '\n';
    std::cout << name_1 << " has " << std::strlen(name_1) << " letters.\n";
    std::cout << name_1 << " has " << std::size(name_1) << " indexs in the array.\n";


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "RANDOM QUIZ !" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    How many spaces you typed ?
    */

    char rodzina[255];
    std::cout << "Enter what you want: ";
    std::cin.getline(rodzina, std::size(rodzina));

    int lenghtRodzinka{ static_cast<int>(std::strlen(rodzina)) };
    int spaces{ 0 };

    for(int index{ 0 }; index < lenghtRodzinka; ++index)
    {
        if(rodzina[index] == ' ')
        {
            ++spaces;
        }
    }
    if(spaces > 0)
    {
        std::cout << "You have: " << spaces << " spaces\n";
    }
    else if(spaces == 0)
    {
        std::cout << "You did not enter spaces.";
    }

    return 0;
}