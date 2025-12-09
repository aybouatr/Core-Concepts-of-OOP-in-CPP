#include "../include/MateriaSource.hpp"



MateriaSource::MateriaSource()
{
	for (int i = 0; i < NUMBER_MATERIA; i++)
	{
		if (i < 4)
			_table[i] = NULL;
		Save[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) : IMateriaSource()
{
	for (int i = 0; i < NUMBER_MATERIA; i++)
	{
		if (i < 4)
		{
			if (!src._table[i])
				_table[i] = NULL;
			else
				_table[i] = src._table[i]->clone();
		}
		Save[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
	for (int i = 0; i < NUMBER_MATERIA; i++)
	{
		if (i < 4)
		{
			if (_table[i])
				delete _table[i];
			if (!src._table[i])
				_table[i] = NULL;
			else
				_table[i] = src._table[i]->clone();
		}
		Save[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_table[i])
			MemoryCollector(_table[i]);
	}
	Delete_gc();
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_table[i])
		{
			_table[i] = materia->clone();
			return ;
		}
	}
	// MemoryCollector (materia);
}

bool MateriaSource::Not_double(AMateria* materia)
{
	for(int i = 0; i < NUMBER_MATERIA ; i++)
	{
		if (Save[i])
		{
			if (Save[i] == materia)
				return false;
		}
		else
			return true;
	}
	return (true);
}

void MateriaSource::MemoryCollector(AMateria *materia)
{
	int i;

	for (i = 0 ; i < NUMBER_MATERIA;i++)
	{
		if (!Save[i])
		{
			if (Not_double(materia))
				Save[i] = materia;
			return;
		}
	}
	if (i == NUMBER_MATERIA)
	{
		std::cout << "The garbage collector is full, so I'm deleting this materia now." << std::endl;
		delete materia;
		materia = NULL;
	}
}

void MateriaSource::Delete_gc()
{
	for (int i = 0 ; i < NUMBER_MATERIA;i++)
	{
		if (Save[i])
		{
			delete Save[i];
			Save[i] = NULL;
		}
	}
}


AMateria*	MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_table[i]->getType() == type)
		{
			AMateria * materia = _table[i]->clone();
			MemoryCollector(materia);
			return (materia);
		}
	}
	return (NULL);
}