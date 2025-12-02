#pragma one

#include "Animal"

class Dog : public Animal
{
public:

    virtual void makeSound();

};


void Dog::makeSound()
{
    std::cout << "the Dog made Sound Dog " << std::endl;
}