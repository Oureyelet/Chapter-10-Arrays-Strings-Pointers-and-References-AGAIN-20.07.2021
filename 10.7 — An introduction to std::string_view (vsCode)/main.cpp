#include <iostream>
#include <string> //std::string
#include <string_view> // std::string_view
#include <iterator> // srd::size()

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
    In the previous lesson, we talked about C-style strings, and the dangers of using them. 
    C-style strings are fast, but they’re not as easy to use and as safe as std::string.

    But std::string (which we covered in lesson 4.12 -- An introduction to std::string), 
    has some of its own downsides, particularly when it comes to const strings.

    Consider the following example:
    */
    char text[]{ "hello" };
    std::string str{ text };
    std::string more{ str };

    std::cout << text << ' ' << str << ' ' << more << '\n';


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Introducing std::string_view" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Consider a window in your house, looking at a car sitting on the street. 
    You can look through the window and see the car, but you can’t touch or move the car. 
    Your window just provides a view to the car, which is a completely separate object.

    C++17 introduces another way of using strings, std::string_view, 
    which lives in the <string_view> header.

    Unlike std::string, which keeps its own copy of the string, std::string_view provides 
    a view of a string that is defined elsewhere.

    We can re-write the above code to use std::string_view by replacing every std::string 
    with std::string_view.
    */
    std::string_view text1{ "hello" };// view the text "hello", which is stored in the binary
    std::string_view str1{ text1 };// view of the same "hello"
    std::string_view more1{ str1 };// view of the same "hello"

    std::cout << text1 << ' ' << str1 << ' ' << more1 << '\n';

    /*
    The output is the same, but no more copies of the string “hello” are created. 
    The string “hello” is stored in the binary and is not allocated at run-time. 
    text is only a view onto the string “hello”, so no copy has to be created. 
    When we copy a std::string_view, the new std::string_view observes the same string 
    as the copied-from std::string_view is observing. This means that neither str nor more 
    create any copies. They are views onto the existing string “hello”.

    std::string_view is not only fast, but has many of the functions that we know from std::string.
    */
    std::string_view string{ "Trains are fast!" };

    std::cout << string.length() << '\n';// Return lenght of our string which is 16
    std::cout << string.substr(0, string.find(' ')) << '\n';
    /*
    The substring is the portion of the object that starts at character position pos and 
    spans len characters (or until the end of the string, whichever comes first). This return
    only Trains because he stoped with first spaces foud.
    */
    std::cout << ( string == "Trains areast!" ) << '\n';// if our string is equal... then return 1 or 0


    /*
    Best practice

    Use std::string_view instead of C-style strings.
    Prefer std::string_view over std::string for read-only strings, 
    unless you already have a std::string.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "View modification functions" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Back to our window analogy, consider a window with curtains. We can close either the left or 
    right curtain to reduce what we can see. We don’t change what’s outside, we just reduce the 
    visible area.

    Similarly, std::string_view contains functions that let us manipulate the view of the string. 
    This allows us to change the view without modifying the viewed string.

    The functions for this are remove_prefix, which removes characters from the left side of the 
    view, and remove_suffix, which removes characters from the right side of the view.
    */
    std::string_view fruit{ "Peach" };

    std::cout << fruit << '\n';

    fruit.remove_prefix(1);// Ignore the first character.
    std::cout << fruit << '\n';


    fruit.remove_suffix(2);// Ignore the last 2 characters.
    std::cout << fruit << '\n';
    /*
    Unlike real curtains, a std::string_view cannot be opened back up. 
    Once you change the visible area, you can’t go back (There are tricks which we won’t go into).
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "std::string_view works with non-null-terminated strings" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Unlike C-style strings and std::string, std::string_view doesn’t use null terminators 
    to mark the end of the string. Rather, it knows where the string ends because it keeps 
    track of its length.
    */
    




    return 0;
}