#include "../include/Character.hpp"


Character::Character()
{
	_name = "D_Name";
	for (int i = 0; i < NUMBER_MATERIA; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name)
{
	_name = name;
	for (int i = 0; i < NUMBER_MATERIA; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &src)
{
	for (int i = 0; i < NUMBER_MATERIA; i++)
	{
		if (src._inventory[i] == NULL)
			_inventory[i] = NULL;
		else
		{
			_inventory[i] = src._inventory[i]->clone();
		}
	}
	_name = src._name;
}

Character& Character::operator=(const Character &src)
{
	for (int i = 0; i < NUMBER_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (src._inventory[i] == NULL)
			_inventory[i] = NULL;
		else
			_inventory[i] = src._inventory[i]->clone();
	}
	_name = src._name;
	return (*this);
}
