#include "../include/Animal.hpp"


Animal::Animal():_type("Animal")
{
    std::cout << "Animal has been created call constarctor." << std::endl;
}

Animal::Animal(const Animal& other)
{
   
    std::cout <<  "Animal has been created call (copy constarctor)." << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        std::cout <<  "Animal has been assigned (copy assignment called)" << std::endl;
        this->_type = other._type;
    }
    return *this;
}


void Animal::setType(const std::string type)
{
    this->_type = type;
}

std::string Animal::getType() const
{
    return (_type);
}

Animal::~Animal()
{
    std::cout << "Animal call desractor " << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Sound Animal " << std::endl;
}