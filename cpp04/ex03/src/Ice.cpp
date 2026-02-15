#include "../include/Ice.hpp"





Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &src)
{
	type = src.type;
}

Ice& Ice::operator=(const Ice &src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}

Ice::~Ice()
{
}

AMateria*	Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}