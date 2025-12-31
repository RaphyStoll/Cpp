#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "libftpp.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base * generate(void)
{
	int i = std::rand() % 3;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	std::cout << "Unknown" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	std::cout << pad_line("TESTING IDENTIFY") << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << std::endl << "Test " << i + 1 << ":" << std::endl;
		Base* ptr = generate();
		
		std::cout << "Identify by pointer: ";
		identify(ptr);

		std::cout << "Identify by reference: ";
		identify(*ptr);

		delete ptr;
	}

	return 0;
}
