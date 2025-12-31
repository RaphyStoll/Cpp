#include "C.hpp"

C::C() {}

C::C(C const & src) : Base(src)
{
	*this = src;
}

C & C::operator=(C const & rhs)
{
	if (this != &rhs)
	{
		Base::operator=(rhs);
	}
	return *this;
}

C::~C() {}
