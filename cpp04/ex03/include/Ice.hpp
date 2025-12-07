#pragma once

#include "AMateria.hpp"


class Ice : public AMateria
{

public:

    Ice();
    Ice(const Ice &I);
    Ice& operator=(const Ice &other);
    ~Ice();

    AMateria* clone() const override;
    void use(ICharacter& target) override;
};


