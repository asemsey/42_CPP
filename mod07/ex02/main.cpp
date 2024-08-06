#include <iostream>
#include <cstdlib>
#include "Array.hpp"

// #define MAX_VAL 750
#define MAX_VAL 5
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    std::cout << "default values:\t\t" << numbers;

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "random values:\t\t" << numbers;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "assignment operator:\t" << tmp;
        std::cout << "copy constructor:\t" << test;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        std::cout << "index low: ";
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "index high: ";
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand() % 100;
    }
    std::cout << "new values:\t\t" << numbers;
    delete[] mirror;
    return 0;
}