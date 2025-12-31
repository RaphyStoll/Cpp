#pragma once

class Base
{
	public:
		Base();
		Base(Base const & src);
		Base & operator=(Base const & rhs);
		virtual ~Base();
};
