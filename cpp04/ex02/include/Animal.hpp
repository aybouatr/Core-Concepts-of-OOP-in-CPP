#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"


class Animal
{

protected:
    std::string _type;
  
public:

    Animal();
    Animal(const Animal &other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    virtual void makeSound() const = 0;
    void setType(const std::string);
    std::string getType() const ;

};



