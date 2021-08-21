#include <iostream>
#include <string> //std::string
#include <string_view> // std::string_view
#include <iterator> // srd::size()

#ifndef FIRST_H
#define FIRST_H

std::string askForName()
{
    std::cout << "What's your name?\n";

    // Use a std::string, because std::cin needs to modify it.
    std::string name{};
    std::getline(std::cin, name);

    std::cout << "Hello " << name << '\n';

    return name;
}

void print(std::string s)
{
    std::cout << s << '\n';
}

#endif // end of FIRST_H