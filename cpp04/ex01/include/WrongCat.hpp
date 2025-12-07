#pragma once
#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
private:
    Brain* brain;
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();

    void makeSound() const ;
};

