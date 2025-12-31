#pragma once
#include "Base.hpp"

class C : public Base
{
	public:
		C();
		C(C const & src);
		C & operator=(C const & rhs);
		~C();
};
