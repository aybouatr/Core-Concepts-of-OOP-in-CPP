#pragma once

#include "ICharacter.hpp"
#include "Materia"

#define NUMBER_MATERIA 4

class Character : public ICharacter
{

    private:
        std::string	_name;
        AMateria*	_inventory[NUMBER_MATERIA];
	
	protected:
		AMateria *Save;
		int index_gc;
		int size_gc;
		void _memoryCollector(AMateria *materia);

    public:
		Character();
		Character(const std::string &name);
		Character(const Character &src);
		Character& operator=(const Character &src);
		~Character();
	
		const std::string &getName() const;
		AMateria*	getMateria(int idx) const;

		void equip(AMateria *materia);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

};

void Character::_memoryCollector(AMateria *materia)
{


}

