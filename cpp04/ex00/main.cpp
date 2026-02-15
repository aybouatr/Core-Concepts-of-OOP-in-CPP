#include <iostream>

#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongCat.hpp"



int main()
{
    std::cout << "--------------------- correct Way ---------------------\n\n" ;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "this object type " <<j->getType() << " " << std::endl;
    std::cout << "this object type " << i->getType() << " " << std::endl;
    meta->makeSound();
    i->makeSound();
    j->makeSound();
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n\n--------------------- Wrong Way ---------------------\n\n" ;
    
    
    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    std::cout << "this object type " <<wrong->getType() << " " << std::endl;
    delete wrong;

return 0;
}