#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
    setType("Cat");
    brain = new Brain();
    std::cout << "Cat has been created (default constructor)." << std::endl;
}


Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat has been created (copy constructor)." << std::endl;
     this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        std::cout << "Cat has been assigned (copy assignment)." << std::endl;
        this->brain = other.brain;
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}
