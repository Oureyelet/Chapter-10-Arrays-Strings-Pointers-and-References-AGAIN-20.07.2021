#include <iostream>

void doSomething()
{
    int* ptr_3{ new int{} };
}

int main()
{
    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "The need for dynamic memory allocation" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    C++ supports three basic types of memory allocation, of which you’ve already seen two.

    Static memory allocation happens for static and global variables. Memory for these types of variables is allocated once 
    when your program is run and persists throughout the life of your program.
    Automatic memory allocation happens for function parameters and local variables. Memory for these types of variables is 
    allocated when the relevant block is entered, and freed when the block is exited, as many times as necessary.
    Dynamic memory allocation is the topic of this article.

    Both static and automatic allocation have two things in common:

    The size of the variable / array must be known at compile time.
    Memory allocation and deallocation happens automatically (when the variable is instantiated / destroyed).

    Most of the time, this is just fine. However, you will come across situations where one or both of these constraints cause 
    problems, usually when dealing with external (user or file) input.

    For example, we may want to use a string to hold someone’s name, but we do not know how long their name is until they enter 
    it. Or we may want to read in a number of records from disk, but we don’t know in advance how many records there are. Or we 
    may be creating a game, with a variable number of monsters (that changes over time as some monsters die and new ones are 
    spawned) trying to kill the player.

    If we have to declare the size of everything at compile time, the best we can do is try to make a guess the maximum size of 
    variables we’ll need and hope that’s enough:

    char name[25]; // let's hope their name is less than 25 chars!
    Record record[500]; // let's hope there are less than 500 records!
    Monster monster[40]; // 40 monsters maximum
    Polygon rendering[30000]; // this 3d rendering better not have more than 30,000 polygons!

    This is a poor solution for at least four reasons:

    First, it leads to wasted memory if the variables aren’t actually used. For example, if we allocate 25 chars for every name, 
    but names on average are only 12 chars long, we’re using over twice what we really need. Or consider the rendering array 
    above: if a rendering only uses 10,000 polygons, we have 20,000 Polygons worth of memory not being used!

    Second, how do we tell which bits of memory are actually used? For strings, it’s easy: a string that starts with a \0 is 
    clearly not being used. But what about monster[24]? Is it alive or dead right now? That necessitates having some way to tell 
    active from inactive items, which adds complexity and can use up additional memory.

    Third, most normal variables (including fixed arrays) are allocated in a portion of memory called the stack. The amount of 
    stack memory for a program is generally quite small -- Visual Studio defaults the stack size to 1MB. If you exceed this 
    number, stack overflow will result, and the operating system will probably close down the program.

    On Visual Studio, you can see this happen when running this program:
    */
    int array[1000000];// allocate 1 million integers (probably 4MB of memory)

    /*
    Being limited to just 1MB of memory would be problematic for many programs, especially those that deal with graphics.

    Fourth, and most importantly, it can lead to artificial limitations and/or array overflows. What happens when the user 
    tries to read in 600 records from disk, but we’ve only allocated memory for a maximum of 500 records? Either we have to 
    give the user an error, only read the 500 records, or (in the worst case where we don’t handle this case at all) overflow 
    the record array and watch something bad happen.

    Fortunately, these problems are easily addressed via dynamic memory allocation. Dynamic memory allocation is a way for 
    running programs to request memory from the operating system when needed. This memory does not come from the program’s 
    limited stack memory -- instead, it is allocated from a much larger pool of memory managed by the operating system called 
    the heap. On modern machines, the heap can be gigabytes in size.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Dynamically allocating single variables" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    To allocate a single variable dynamically, we use the scalar (non-array) form of the new operator:
    */
    new int;// dynamically allocate an integer (and discard the result)

    /*
    In the above case, we’re requesting an integer’s worth of memory from the operating system. The new operator creates the 
    object using that memory, and then returns a pointer containing the address of the memory that has been allocated.

    Most often, we’ll assign the return value to our own pointer variable so we can access the allocated memory later.
    */
    int* ptr{ new int };// dynamically allocate an integer and assign the address to ptr so we can access it later
    //We can then perform indirection through the pointer to access the memory:

    *ptr = 7;// assign value of 7 to allocated memory

    /*
    If it wasn’t before, it should now be clear at least one case in which pointers are useful. 
    Without a pointer to hold the address of the memory that was just allocated, we’d have no way to access the memory that 
    was just allocated for us!
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "How does dynamic memory allocation work?" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Your computer has memory (probably lots of it) that is available for applications to use. When you run an application, 
    your operating system loads the application into some of that memory. This memory used by your application is divided into 
    different areas, each of which serves a different purpose. One area contains your code. Another area is used for normal 
    operations (keeping track of which functions were called, creating and destroying global and local variables, etc…). 
    We’ll talk more about those later. However, much of the memory available just sits there, waiting to be handed out to 
    programs that request it.

    When you dynamically allocate memory, you’re asking the operating system to reserve some of that memory for your 
    program’s use. If it can fulfill this request, it will return the address of that memory to your application. From that 
    point forward, your application can use this memory as it wishes. When your application is done with the memory, it can 
    return the memory back to the operating system to be given to another program.

    Unlike static or automatic memory, the program itself is responsible for requesting and disposing of dynamically allocated 
    memory.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing a dynamically allocated variable" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    When you dynamically allocate a variable, you can also initialize it via direct initialization or uniform initialization:
    */
    int* ptr2{ new int (5) };// use direct initialization
    int* ptr3{ new int {7} };// use uniform initialization


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Deleting single variables" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    When we are done with a dynamically allocated variable, we need to explicitly tell C++ to free the memory for reuse. 
    For single variables, this is done via the scalar (non-array) form of the delete operator:
    */
    // assume ptr has previously been allocated with operator new
    delete ptr;// return the memory pointed to by ptr to the operating system
    ptr = nullptr;// set ptr to be a null pointer


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "What does it mean to delete memory?" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    The delete operator does not actually delete anything. It simply returns the memory being pointed to back to the operating 
    system. The operating system is then free to reassign that memory to another application (or to this application again later).

    Although it looks like we’re deleting a variable, this is not the case! The pointer variable still has the same scope as 
    before, and can be assigned a new value just like any other variable.

    Note that deleting a pointer that is not pointing to dynamically allocated memory may cause bad things to happen.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Dangling pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    C++ does not make any guarantees about what will happen to the contents of deallocated memory, or to the value of the 
    pointer being deleted. In most cases, the memory returned to the operating system will contain the same values it had 
    before it was returned, and the pointer will be left pointing to the now deallocated memory.

    A pointer that is pointing to deallocated memory is called a dangling pointer. Indirection through- or deleting a dangling p
    ointer will lead to undefined behavior.
    */

    /*
    Best practice

    Set deleted pointers to nullptr unless they are going out of scope immediately afterward.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Operator new can fail" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    When requesting memory from the operating system, in rare circumstances, the operating system may not have any memory to 
    grant the request with.

    By default, if new fails, a bad_alloc exception is thrown. If this exception isn’t properly handled (and it won’t be, 
    since we haven’t covered exceptions or exception handling yet), the program will simply terminate (crash) with an unhandled 
    exception error.

    In many cases, having new throw an exception (or having your program crash) is undesirable, so there’s an alternate 
    form of new that can be used instead to tell new to return a null pointer if memory can’t be allocated. This is done by 
    adding the constant std::nothrow between the new keyword and the allocation type:
    */
    int* our_new_int{ new (std::nothrow) int }; // value will be set to a null pointer if the integer allocation fails

    /*
    In the above example, if new fails to allocate memory, it will return a null pointer instead of the address of the 
    allocated memory.

    Note that if you then attempt indirection through this pointer, undefined behavior will result (most likely, your program 
    will crash). Consequently, the best practice is to check all memory requests to ensure they actually succeeded before using 
    the allocated memory.
    */
    int* our_second{ new (std::nothrow) nwe{} };// ask for an integer's worth of memory

    if(!our_second)
    {
        // Do error handling here
        std::cout << "Could not allocate memory\n";
    }
    //Because asking new for memory only fails rarely (and almost never in a dev environment), it’s common to forget to do 
    //this check!


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Null pointers and dynamic memory allocation" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Memory leaks" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Dynamically allocated memory stays allocated until it is explicitly deallocated or until the program ends 
    (and the operating system cleans it up, assuming your operating system does that). However, the pointers used to hold 
    dynamically allocated memory addresses follow the normal scoping rules for local variables. This mismatch can create 
    interesting problems.

    Consider the following function:
    */
    doSomething(); // look above main();

    /*
    This function allocates an integer dynamically, but never frees it using delete. Because pointers variables are just 
    normal variables, when the function ends, ptr will go out of scope. And because ptr is the only variable holding the 
    address of the dynamically allocated integer, when ptr is destroyed there are no more references to the dynamically 
    allocated memory. This means the program has now “lost” the address of the dynamically allocated memory. As a result, 
    this dynamically allocated integer can not be deleted.
    */

    /*
    This is called a memory leak. Memory leaks happen when your program loses the address of some bit of dynamically allocated 
    memory before giving it back to the operating system. When this happens, your program can’t delete the dynamically allocated 
    memory, because it no longer knows where it is. The operating system also can’t use this memory, because that memory is 
    considered to be still in use by your program.

    Memory leaks eat up free memory while the program is running, making less memory available not only to this program, 
    but to other programs as well. Programs with severe memory leak problems can eat all the available memory, causing the 
    entire machine to run slowly or even crash. Only after your program terminates is the operating system able to clean 
    up and “reclaim” all leaked memory.

    Although memory leaks can result from a pointer going out of scope, there are other ways that memory leaks can result. 
    For example, a memory leak can occur if a pointer holding the address of the dynamically allocated memory is assigned 
    another value:
    */
    int value{ 5 };
    int* ptr_7{ new int{} };// allocate memory
    ptr_7 = &value// old address lost, memory leak results

    //This can be fixed by deleting the pointer before reassigning it:

    int value_x{ 5 };
    int* ptr_7_x{ new int{} };// allocate memory
    delete ptr_7_x;// return memory back to operating system
    ptr_7_x = &value_x;// old address lost, memory leak results

    //Relatedly, it is also possible to get a memory leak via double-allocation:

    int* ptr_8{ new int{} };
    ptr_8 = new int{};
    /*
    The address returned from the second allocation overwrites the address of the first allocation. Consequently, 
    the first allocation becomes a memory leak!

    Similarly, this can be avoided by ensuring you delete the pointer before reassigning.
    */


    std::cout << std::endl;
    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Conclusion" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    /*
    Operators new and delete allow us to dynamically allocate single variables for our programs.

    Dynamically allocated memory has dynamic duration and will stay allocated until you deallocate it or the 
    program terminates.

    Be careful not to perform indirection through dangling or null pointers.

    In the next lesson, we’ll take a look at using new and delete to allocate and delete arrays.
    */










    

    return 0;
}