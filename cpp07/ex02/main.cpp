#include "include/Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


#define MAX_VAL 5

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);

    int* mirror = new int[MAX_VAL];

    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = i;
        numbers[i] = value;
        mirror[i] = value;
    }
   
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
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
        numbers[-20] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = i;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " ";
    }

    delete [] mirror;

    return 0;
}