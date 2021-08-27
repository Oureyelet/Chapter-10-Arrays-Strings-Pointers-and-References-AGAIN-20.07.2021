#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void printSize(int* array)
{
    // array is treated as a pointer here
    std::cout << sizeof(array) << '\n';// prints the size of a pointer, not the size of the array!
}

// C++ will implicitly convert parameter array[] to *array
void printSize_two(int array[])
{
    // array is treated as a pointer here, not a fixed array
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

#endif // end FUNCTIONS_H