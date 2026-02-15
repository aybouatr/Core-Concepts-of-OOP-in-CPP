#include <iostream>

#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"



int main()
{
    std::cout << "===== Creating array of Animals =====\n\n" << std::endl;

    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Animal Animal; // can't de

    

    return 0;
}