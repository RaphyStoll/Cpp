#include "B.hpp"

B::B() {}

B::B(B const & src) : Base(src)
{
	*this = src;
}

B & B::operator=(B const & rhs)
{
	if (this != &rhs)
	{
		Base::operator=(rhs);
	}
	return *this;
}

B::~B() {}
