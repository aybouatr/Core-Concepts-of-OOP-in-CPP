#include "../include/WrongAnimal.hpp"



WrongAnimal::WrongAnimal():_type("WrongAnimal")
{
    std::cout << "WrongAnimal has been created call constarctor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout <<  "WrongAnimal has been created call (copy constarctor)." << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        std::cout <<  "WrongAnimal has been assigned (copy assignment called)" << std::endl;
        this->_type = other._type;
    }
    return *this;
}


void WrongAnimal::setType(const std::string type)
{
    this->_type = type;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal call desractor " << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Sound WrongAnimal " << std::endl;
}