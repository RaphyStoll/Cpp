#include "Point.hpp"

Point::Point(void) {
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::Point(const float x, const float y)
{
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::Point(const Point &other) {
	this->_x = other._x;
	this->_y = other._y;
}

Point::~Point(void) {
}

Point& Point::operator=(const Point &other) {
	if (this != &other) {
		this->_x = other._x;
		this->_y = other._y;
	}
	return *this;
}

Fixed Point::getX(void) const {
	return this->_x;
}

Fixed Point::getY(void) const {
	return this->_y;
}
