#include "../include/Brain.hpp"


Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "thinking";
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy Constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain Copy Assignment Operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}