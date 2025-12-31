#pragma once
#include "Base.hpp"

class A : public Base
{
	public:
		A();
		A(A const & src);
		A & operator=(A const & rhs);
		~A();
};
