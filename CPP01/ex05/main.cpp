#include <iostream>
#include "harl.hpp"

int main()
{
	Harl harl;

	std::cout << "DEBUG -> ";
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "INFO -> ";
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "WARNING -> ";
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "ERROR -> ";
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "INVALID -> ";
	harl.complain("INVALID"); // test fail

	return 0;
}