

#include "Harl.hpp"

int main (int argc, char **argv)
{
	std::string level;
	Harl harl;
	
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments!\n";
		return (0);
	}
	level = argv[1];
	harl.complain(level);
	return (0);
}