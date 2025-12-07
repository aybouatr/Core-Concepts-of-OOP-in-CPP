#pragma once


#include <iostream>

class AMateria
{
protected:
    std::string  type;

public:

    AMateria(std::string const & type);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

};

std::string const & getType() const
{
    return (type);
}

AMateria::AMateria(std::string const &type)
{
    this.type = type;
}

AMateria::AMateria(const AMateria &src)
{
	type = src.type;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		type = src.type;
	return (*this);
}

