#include "../include/Zombie.hpp"

Zombie *newZombie( std::string name )
{
	Zombie* Z;
	
	Z = new Zombie(name);
	return (Z);
}
