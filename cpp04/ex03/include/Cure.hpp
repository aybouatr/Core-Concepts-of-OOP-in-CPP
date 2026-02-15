#pragma once

#include "AMateria.hpp"


class Cure : public AMateria
{

public:

    Cure();
    Cure(const Cure &I);
    Cure& operator=(const Cure &other);
    ~Cure();

    AMateria* clone() const override;
    void use(ICharacter& target) override;

};