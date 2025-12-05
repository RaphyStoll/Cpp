#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor called for type: " << _type << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	std::cout << "AMateria copy constructor called for type: " << _type << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria assignment operator called for type: " << _type << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called for type: " << _type << std::endl;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << _type << " used on " << target.getName() << std::endl;
}
