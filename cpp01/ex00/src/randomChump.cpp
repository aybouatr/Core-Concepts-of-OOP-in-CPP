#include "../include/Zombie.hpp"

void randomChump(std::string name)
{
	Zombie rand_Chump(name);
	rand_Chump.announce();
}