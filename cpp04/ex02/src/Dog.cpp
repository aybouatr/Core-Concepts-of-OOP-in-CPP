#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
    setType("Dog");
    brain = new Brain();
    std::cout << "Dog has been created (default constructor)." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog has been created (copy constructor)." << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        std::cout << "Dog has been assigned (copy assignment)." << std::endl;
        for(int i = 0;i < 100 ; i++)
            this->brain[i] = other.brain[i];
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
