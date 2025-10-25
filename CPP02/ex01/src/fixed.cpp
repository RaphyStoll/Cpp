#include "fixed.hpp"
#include "debug.hpp"
#include <iostream>
#include <cmath>

#ifdef DEBUG
# undef DEBUG
#endif

#define DEBUG 1

Fixed::Fixed(void) {
	_value = 0;
	print_debug("Default constructor called");
}

Fixed::Fixed(const int n)
{
    print_debug("Int constructor called");
    this->_value = n << this->_fractionalBits;  // n × 256
}

Fixed::Fixed(const float f)
{
    print_debug("Float constructor called");
    this->_value = roundf(f * (1 << this->_fractionalBits));  // f × 256, arrondi
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

float Fixed::toFloat(void) const
{
    return (float)this->_value / (1 << this->_fractionalBits);  // _value ÷ 256
}

int Fixed::toInt(void) const
{
    return this->_value >> this->_fractionalBits;  // _value ÷ 256 (division entière)
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}