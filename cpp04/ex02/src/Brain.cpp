#include "../include/Brain.hpp"



Brain::Brain()
{
    std::cout << "Brain Call default Constarctor" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Call  Destarctor" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}