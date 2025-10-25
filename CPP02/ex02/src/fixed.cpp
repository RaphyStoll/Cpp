#include "fixed.hpp"
#include "debug.hpp"
#include <iostream>
#include <cmath>
#include <sstream>

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

bool Fixed::operator>(const Fixed &other) const {
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_value * other._value) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {

	Fixed result;
	result.setRawBits((this->_value << _fractionalBits) / other._value);
	return result;
}

// PRÉ-incrémentation: modifie et retourne *this
Fixed &Fixed::operator++(void) {
	this->_value++;  // Ajoute 1 raw bit (= epsilon)
	return *this;
}

// POST-incrémentation: sauvegarde, modifie, retourne l'ancien
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);  // Copie l'état actuel
	this->_value++;    // Modifie
	return tmp;        // Retourne l'ancien état
}

// PRÉ-décrémentation
Fixed &Fixed::operator--(void) {
	this->_value--;
	return *this;
}

// POST-décrémentation
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	std::ostringstream oss;
	oss << "setRawBits member function called (" << raw << ")";
	print_debug(oss.str());
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
// ternaire (condition) ? si oui : si non
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

// pareil -> const
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

// pareil -> const
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}