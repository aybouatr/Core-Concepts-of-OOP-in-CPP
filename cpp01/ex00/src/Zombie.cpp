#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie \"" << _name << "\" created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie \"" << _name << "\" destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}