#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"


class WrongAnimal
{

protected:
    std::string _type;

public:

    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();

    void makeSound() const;
    void setType(const std::string);
    std::string getType() const ;

};


