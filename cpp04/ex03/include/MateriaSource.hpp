#pragma once 

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"


class	IMateriaSource;

class	MateriaSource : virtual public IMateriaSource
{
	protected:
		AMateria *Save[NUMBER_MATERIA];
		void MemoryCollector(AMateria *materia);
		void Delete_gc();
		bool Not_double(AMateria* materia);
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource& operator=(const MateriaSource &src);
		~MateriaSource();

		void	learnMateria(AMateria *materia);
		AMateria* createMateria(const std::string &type);
	
	private:
		AMateria*	_table[4];

};
