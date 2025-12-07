#include <iostream>

#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongCat.hpp"



int main()
{

    Animal* A = new Dog();

    A->makeSound();

    delete A;


    // const int size = 10;
    // Animal* animals[size];

    // for (int i = 0; i < size / 2; i++)
    //     animals[i] = new Dog();

    // for (int i = size / 2; i < size; i++)
    //     animals[i] = new Cat();

    // for (int j = 0; j < 10 ;j++)
    //     delete animals[j];













return 0;
}