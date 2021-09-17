#include <iostream>
#include <cassert> // for assert();

enum class Type
{
    tInt, // note: we can't use "int" here because it's a keyword, so we'll use "tInt" instead
    tFloat,
    tCstring
};

void printValue(void* ptr, Type type)
{
    switch (type)
    {
        case Type::tInt:
            std::cout << *static_cast<int*>(ptr) << '\n';// cast to int pointer and perform indirection
            break;
        case Type::tFloat:
            std::cout << *static_cast<float*>(ptr) << '\n';// cast to float pointer and perform indirection
            break;
        case Type::tCstring:
            std::cout << static_cast<char*>(ptr) << '\n';
            /*
            Cast to char pointer (no indirection) std::cout knows to treat char* as a C-style string
            if we were to perform indirection through the result, then we'd just print the single char 
            that ptr is pointing to
            */
            break;
        default:
            assert(false && "type not found");
            break;
    }
}

int main()
{
    std::cout << "Hello World\n";

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Void pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    The void pointer, also known as the generic pointer, is a special type of pointer that can be pointed at objects of 
    any data type! A void pointer is declared like a normal pointer, using the void keyword as the pointer’s type:
    */
    void* ptr{};// ptr is a void pointer

    //A void pointer can point to objects of any data type:
    int nValue{};
    float fValue{};

    struct Something
    {
        int n;
        float f;
    };

    Something sValue;

    void* clear_ptr;

    clear_ptr = &nValue;// valid
    clear_ptr = &fValue;// valid
    clear_ptr = &sValue;// valid
    /*
    However, because the void pointer does not know what type of object it is pointing to, dereferencing 
    a void pointer is illegal. Instead, the void pointer must first be cast to another pointer type before the 
    dereference can be performed.
    */
    int value{ 5 };
    void* void_Value{ &value };

    //std::cout << void_Value << '\n'; // illegal: dereference of void pointer

    int* ptr_int_Value{ static_cast<int*>(void_Value) };// however, if we cast our void pointer to an int pointer...

    std::cout << *ptr_int_Value << '\n';// then we can dereference the result
    /*
    The next obvious question is: If a void pointer doesn’t know what it’s pointing to, how do we know what to cast it to? 
    Ultimately, that is up to you to keep track of.

    Here’s an example of a void pointer in use:
    */
    int tValue_i{ 5 };
    float tValue_f{ 7.5f };
    char szValue[]{ "Mollie" };

    printValue(&tValue_i, Type::tInt);
    printValue(&tValue_f, Type::tFloat);
    printValue(&szValue, Type::tCstring);


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Void pointer miscellany" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Void pointers can be set to a null value:
    */
    void* ptr{ nullptr };// ptr is a void pointer that is currently a null pointer
    /*
    Although some compilers allow deleting a void pointer that points to dynamically allocated memory, doing so should 
    be avoided, as it can result in undefined behavior.

    It is not possible to do pointer arithmetic on a void pointer. This is because pointer arithmetic requires the pointer 
    to know what size object it is pointing to, so it can increment or decrement the pointer appropriately.

    Note that there is no such thing as a void reference. This is because a void reference would be of type void &, and 
    would not know what type of value it referenced.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Conclusion" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    In general, it is a good idea to avoid using void pointers unless absolutely necessary, as they effectively allow you to 
    avoid type checking. This allows you to inadvertently do things that make no sense, and the compiler won’t complain about it. 
    For example, the following would be valid:

    int nValue{ 5 };
    printValue(&nValue, Type::tCString);

    But who knows what the result would actually be!

    Although the above function seems like a neat way to make a single function handle multiple data types, C++ actually 
    offers a much better way to do the same thing (via function overloading) that retains type checking to help prevent misuse. 
    Many other places where void pointers would once be used to handle multiple data types are now better done using templates, 
    which also offer strong type checking.

    However, very occasionally, you may still find a reasonable use for the void pointer. Just make sure there isn’t a better 
    (safer) way to do the same thing using other language mechanisms first!
    */


    return 0;
}