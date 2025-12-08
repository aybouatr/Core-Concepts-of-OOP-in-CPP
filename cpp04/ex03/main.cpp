#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <exception>

int main()
{

   IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    
    ICharacter* me = new Character("me");
    
    for (int i = 0; i < 10; i++)
    {
        AMateria* tmp = src->createMateria("ice");
        me->equip(tmp);   // positions 4-9 should NOT leak
    }
    
    delete me;
    delete src;


}