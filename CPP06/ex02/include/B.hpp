#pragma once
#include "Base.hpp"

class B : public Base
{
	public:
		B();
		B(B const & src);
		B & operator=(B const & rhs);
		~B();
};
