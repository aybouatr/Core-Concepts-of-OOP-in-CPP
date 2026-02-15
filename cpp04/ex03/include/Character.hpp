#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"


#define NUMBER_MATERIA 1024


class Character : public ICharacter
{

    private:
        std::string	_name;
        AMateria*	_inventory[4];
	
	protected:
		AMateria *Save[NUMBER_MATERIA];
		void MemoryCollector(AMateria *materia);
		void Delete_gc();
		bool Not_double(AMateria* materia);


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


