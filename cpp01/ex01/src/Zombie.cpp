#include "../include/Zombie.hpp"

Zombie::Zombie()
{
	
}

Zombie::~Zombie()
{
	std::cout << "Zombie \"" << _name << "\" destroyed" << std::endl;
}

void Zombie::set_name(std::string name)
{
	_name = name;
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}