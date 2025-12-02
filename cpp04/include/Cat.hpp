#pragma one
#include "Animal.hpp"


class Cat : public Animal
{

public:

    Cat();
    void Cat(const std::string& type);
    void Cat(const Animal &type);
    Animal& operator=(const Animal& other);
    ~Cat();

    virtual void makeSound();

};


void Dog::makeSound()
{
    std::cout << "the Cat made Sound Cat " << std::endl;
}