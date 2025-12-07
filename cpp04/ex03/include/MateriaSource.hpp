#pragma once 

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"


class	MateriaSource : virtual public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource& operator=(const MateriaSource &src);
		~MateriaSource();

		void	learnMateria(AMateria *materia);
		AMateria* createMateria(const std::string &type);
	
	private:
		AMateria*	_table[NUMBER_MATERIA];

};