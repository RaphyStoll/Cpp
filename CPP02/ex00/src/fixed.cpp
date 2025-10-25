#include "fixed.hpp"
#include "debug.hpp"
#include <iostream>

#ifdef DEBUG
# undef DEBUG
#endif

#define DEBUG = 1

Fixed::Fixed(void) {
	_value = 0;
	print_debug("Default constructor called");
}

Fixed::~Fixed(void) {
	print_debug("Default destructor called");
}

Fixed::Fixed(const Fixed &other) {
	print_debug("Copy constructor called");
	this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed &other) {
	print_debug("Copy assignment operator called");
	if (this != &other) {
		this->_value = other._value;
	}
	return *this;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called (" << raw << ")" << std::endl;
	this->_value = raw;
}