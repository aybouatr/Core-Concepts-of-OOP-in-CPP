#include "../include/AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const std::string &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &src)
{
	this->type = src._type;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		type = src._type;
	return (*this);
}

AMateria::~AMateria()
{
}

const std::string& AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "Default attack (no type) on " << target.getName() << std::endl;
}