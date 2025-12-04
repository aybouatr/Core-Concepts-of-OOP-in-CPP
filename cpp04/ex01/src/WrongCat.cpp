#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    setType("WrongCat");
    std::cout << "WrongCat has been created (default constructor)." << std::endl;
}


WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat has been created (copy constructor)." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        std::cout << "WrongCat has been assigned (copy assignment)." << std::endl;
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}