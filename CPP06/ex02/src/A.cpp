#include "A.hpp"

A::A() {}

A::A(A const & src) : Base(src)
{
	*this = src;
}

A & A::operator=(A const & rhs)
{
	if (this != &rhs)
	{
		Base::operator=(rhs);
	}
	return *this;
}

A::~A() {}
