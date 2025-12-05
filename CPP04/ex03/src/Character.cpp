#include "Character.hpp"
#include <iostream>

void Character::_initInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		_inventory[i] = NULL;
	}
	_equippedCount = 0;
	_floorCount = 0;
	for (int i = 0; i < MAX_FLOOR_MATERIAS; ++i)
	{
		_floorMaterias[i] = NULL;
	}
}

void Character::_clearInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	_equippedCount = 0;
}

void Character::_copyInventory(const Character& other)
{
	_clearInventory();
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i] != NULL)
		{
			_inventory[i] = other._inventory[i]->clone();
			_equippedCount++;
		}
		else
		{
			_inventory[i] = NULL;
		}
	}
}

void Character::_clearFloorMaterias()
{
	for (int i = 0; i < _floorCount; ++i)
	{
		if (_floorMaterias[i] != NULL)
		{
			delete _floorMaterias[i];
			_floorMaterias[i] = NULL;
		}
	}
	_floorCount = 0;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character constructor called for " << _name << std::endl;
	_initInventory();
}

Character::Character(const Character& other) : _name(other._name)
{
	std::cout << "Character copy constructor called for " << _name << std::endl;
	_initInventory();
	_copyInventory(other);
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character assignment operator called for " << _name << std::endl;
	if (this != &other)
	{
		_clearInventory();
		_clearFloorMaterias();
		_name = other._name;
		_copyInventory(other);
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called for " << _name << std::endl;
	_clearInventory();
	_clearFloorMaterias();
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Cannot equip NULL Materia." << std::endl;
		return;
	}
	if (_equippedCount >= 4)
	{
		std::cout << _name << "'s inventory is full. Cannot equip " << m->getType() << "." << std::endl;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			_equippedCount++;
			std::cout << _name << " equipped " << m->getType() << " in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << _name << "'s inventory is full (fallback check). Cannot equip " << m->getType() << "." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid inventory index " << idx << " for " << _name << "." << std::endl;
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "No Materia to unequip at slot " << idx << " for " << _name << "." << std::endl;
		return;
	}

	if (_floorCount < MAX_FLOOR_MATERIAS)
	{
		_floorMaterias[_floorCount] = _inventory[idx];
		_floorCount++;
		std::cout << _name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << ". It's now on the floor." << std::endl;
	}
	else
	{
		std::cout << "Floor is full, deleting unequipped Materia: " << _inventory[idx]->getType() << std::endl;
		delete _inventory[idx];
	}

	_inventory[idx] = NULL;
	_equippedCount--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL)
	{
		std::cout << "No Materia to use at slot " << idx << " for " << _name << "." << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
