#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "libftpp.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	srand(time(NULL));
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	std::cout << "\n" << pad_line("Test 1: Intern creates ShrubberyCreationForm") << std::endl;
	try {
		AForm* rrf = someRandomIntern.makeForm("shrubbery creation", "home");
		std::cout << *rrf << std::endl;
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << pad_line("Test 2: Intern creates RobotomyRequestForm") << std::endl;
	try {
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << pad_line("Test 3: Intern creates PresidentialPardonForm") << std::endl;
	try {
		AForm* rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		std::cout << *rrf << std::endl;
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << pad_line("Test 4: Intern tries to create unknown form") << std::endl;
	try {
		AForm* rrf = someRandomIntern.makeForm("unknown form", "target");
		if (rrf) {
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	} catch (std::exception &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n" << pad_line("All tests completed!") << std::endl;
	return 0;
}
