#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "libftpp.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	srand(time(NULL));

	std::cout << "\n" << pad_line("Test 1: ShrubberyCreationForm") << std::endl;
	{
		try {
			Bureaucrat bob("Bob", 137);
			ShrubberyCreationForm shrub("home");
			std::cout << shrub << std::endl;

			bob.signForm(shrub);
			bob.executeForm(shrub);
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 2: RobotomyRequestForm") << std::endl;
	{
		try {
			Bureaucrat alice("Alice", 45);
			RobotomyRequestForm robot("Bender");
			std::cout << robot << std::endl;

			alice.signForm(robot);
			alice.executeForm(robot);
			alice.executeForm(robot);
			alice.executeForm(robot);
			alice.executeForm(robot);
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 3: PresidentialPardonForm") << std::endl;
	{
		try {
			Bureaucrat zaphod("Zaphod", 5);
			PresidentialPardonForm pardon("Arthur Dent");
			std::cout << pardon << std::endl;

			zaphod.signForm(pardon);
			zaphod.executeForm(pardon);
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 4: Execution Failures") << std::endl;
	{
		try {
			Bureaucrat intern("Intern", 150);
			PresidentialPardonForm pardon("Criminal");

			std::cout << "-> Try to execute unsigned form:" << std::endl;
			intern.executeForm(pardon);
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try {
			Bureaucrat boss("Boss", 1);
			Bureaucrat intern("Intern", 150);
			PresidentialPardonForm pardon("Criminal");

			std::cout << "\n-> Try to execute signed form with low grade:" << std::endl;
			boss.signForm(pardon);
			intern.executeForm(pardon);
		}
		catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("All tests completed!") << std::endl;
	return 0;
}
