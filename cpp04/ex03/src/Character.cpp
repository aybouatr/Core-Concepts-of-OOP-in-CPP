#include "../include/Character.hpp"


Character::Character()
{
    _name = "D_Name";
    for (int i = 0; i < NUMBER_MATERIA; i++)
    {
        _inventory[i] = NULL;
        Save[i] = NULL;
    }
}

Character::Character(const std::string &name)
{
    _name = name;
    for (int i = 0; i < NUMBER_MATERIA; i++)
    {
        _inventory[i] = NULL;
        Save[i] = NULL;  
    }
}

Character::Character(const Character &src)
{
    for (int i = 0; i < NUMBER_MATERIA; i++)
    {
        if (src._inventory[i] == NULL)
            _inventory[i] = NULL;
        else
            _inventory[i] = src._inventory[i]->clone();

        Save[i] = NULL;
    }
    _name = src._name;
}

Character& Character::operator=(const Character &src)
{
    if (this == &src)
        return *this;
    for (int i = 0; i < NUMBER_MATERIA; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
        if (src._inventory[i] == NULL)
            _inventory[i] = NULL;
        else
            _inventory[i] = src._inventory[i]->clone();
        Save[i] = NULL;
    }
    _name = src._name;
    return *this;
}

Character::~Character()
{
	for (int i = 0; i < NUMBER_MATERIA; i++)
	{
		if (_inventory[i])
			MemoryCollector(_inventory[i]);
	}
	Delete_gc();
}

const std::string&	Character::getName() const
{
	return (_name);
}

bool Character::Not_double(AMateria* materia)
{
	for (int i = 0 ; i < NUMBER_MATERIA;i++)
	{
		if (Save[i] == materia)
			return false;
	}
	return true;
}

void Character::MemoryCollector(AMateria *materia)
{
	for (int i = 0 ; i < NUMBER_MATERIA;i++)
	{
		if (!Save[i])
		{
			if (Not_double(materia))
				Save[i] = materia;
			return;
		}
	}
}

void Character::Delete_gc()
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

void	Character::equip(AMateria *materia)
{
	Delete_gc();
	for (int i = 0; i < NUMBER_MATERIA; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = materia;
			std::cout << _name <<  ": equipped " << materia->getType() << std::endl;
			return ;
		}
	}
	std::cout << _name << ": no space left for "  << materia->getType()  << std::endl;
}

void	Character::unequip(int index)
{
	if (index < 0 || index > 3)
	{
		std::cout <<  _name <<  ": no Materia found at index "  << index << std::endl;
		return ;
	}
	if (_inventory[index])
	{
		MemoryCollector(_inventory[index]);
		std::cout <<  _name << ": remove from his inventory " << _inventory[index]->getType() << std::endl;
		_inventory[index] = NULL ;
		return ;
	}
	std::cout <<  _name <<  ": no Materia found at index " << index  << std::endl;
}

void	Character::use(int index ,ICharacter &target)
{
	if (_inventory[index])
	{
		_inventory[index]->use(target);
		return ;
	}
	std::cout << _name << ": no Materia found at index " << index << std::endl;
}

AMateria*	Character::getMateria(int index) const
{
	if (index < 0 || index > 3)
	{
		std::cout <<  _name << ": no Materia found at index " << index  << std::endl;
		return (NULL);
	}
	if (_inventory[index])
		return (_inventory[index]);
	std::cout << _name <<  ": no Materia found at index " << index  << std::endl;
	return (NULL);
}