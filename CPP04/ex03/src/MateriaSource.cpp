#include "MateriaSource.hpp"
#include <iostream>

void MateriaSource::_initLearnedMaterias()
{
	for (int i = 0; i < 4; ++i)
	{
		_learnedMaterias[i] = NULL;
	}
	_learnedCount = 0;
}
 
void MateriaSource::_clearLearnedMaterias()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_learnedMaterias[i] != NULL)
		{
			delete _learnedMaterias[i];
			_learnedMaterias[i] = NULL;
		}
	}
	_learnedCount = 0;
}

void MateriaSource::_copyLearnedMaterias(const MateriaSource& other)
{
	_clearLearnedMaterias();
	for (int i = 0; i < 4; ++i)
	{
		if (other._learnedMaterias[i] != NULL)
		{
			_learnedMaterias[i] = other._learnedMaterias[i]->clone();
			_learnedCount++;
		}
		else
		{
			_learnedMaterias[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	_initLearnedMaterias();
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	_initLearnedMaterias();
	_copyLearnedMaterias(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other)
	{
		_clearLearnedMaterias();
		_copyLearnedMaterias(other);
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	_clearLearnedMaterias();
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Cannot learn NULL Materia." << std::endl;
		return;
	}
	if (_learnedCount >= 4)
	{
		std::cout << "MateriaSource is full. Cannot learn " << m->getType() << "." << std::endl;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (_learnedMaterias[i] == NULL)
		{
			_learnedMaterias[i] = m->clone();
			_learnedCount++;
			std::cout << "MateriaSource learned " << m->getType() << " in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full (fallback check). Cannot learn " << m->getType() << "." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_learnedMaterias[i] != NULL && _learnedMaterias[i]->getType() == type)
		{
			std::cout << "MateriaSource creating a " << type << " Materia." << std::endl;
			return _learnedMaterias[i]->clone();
		}
	}
	std::cout << "MateriaSource could not create Materia of type " << type << ". Type unknown." << std::endl;
	return 0;
}
