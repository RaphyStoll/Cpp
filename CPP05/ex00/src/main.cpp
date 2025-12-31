#include "Bureaucrat.hpp"
#include "utils.hpp"
#include <iostream>

int main()
{
	std::cout << "\n" << pad_line("Test 1: Stack Allocation & Getters") << std::endl;
	{
		try {
			Bureaucrat bob("Bob", 1);
			Bureaucrat alice("Alice", 150);

			std::cout << "Created: " << bob << std::endl;
			std::cout << "Name: " << bob.getName() << ", Grade: " << bob.getGrade() << std::endl;

			std::cout << "Created: " << alice << std::endl;
			std::cout << "Name: " << alice.getName() << ", Grade: " << alice.getGrade() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Unexpected exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 2: Heap Allocation") << std::endl;
	{
		Bureaucrat* ptr = NULL;
		try {
			ptr = new Bureaucrat("HeapBureaucrat", 75);
			std::cout << "Created on heap: " << *ptr << std::endl;
			delete ptr;
		}
		catch (std::exception &e) {
			std::cout << "Unexpected exception: " << e.what() << std::endl;
			if (ptr) delete ptr;
		}
	}

	std::cout << "\n" << pad_line("Test 3: Grade Modification (Normal)") << std::endl;
	{
		try {
			Bureaucrat mid("MidLevel", 75);
			std::cout << "Before: " << mid << std::endl;
			
			mid.incrementGrade();
			std::cout << "After increment: " << mid << std::endl;
			
			mid.decrementGrade();
			std::cout << "After decrement: " << mid << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Unexpected exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 4: Exceptions - Instantiation") << std::endl;
	{
		std::cout << "-> Trying to create with grade 0 (Too High):" << std::endl;
		try {
			Bureaucrat tooHigh("TooHigh", 0);
			std::cout << "Error: Should not be printed" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << "Caught expected exception: " << e.what() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Caught generic exception: " << e.what() << std::endl;
		}

		std::cout << "\n-> Trying to create with grade 151 (Too Low):" << std::endl;
		try {
			Bureaucrat tooLow("TooLow", 151);
			std::cout << "Error: Should not be printed" << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << "Caught expected exception: " << e.what() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Caught generic exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 5: Exceptions - Modification") << std::endl;
	{
		std::cout << "-> Incrementing grade 1 (Too High):" << std::endl;
		try {
			Bureaucrat boss("Boss", 1);
			std::cout << boss << std::endl;
			boss.incrementGrade();
			std::cout << "Error: Should not be printed" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << "Caught expected exception: " << e.what() << std::endl;
		}

		std::cout << "\n-> Decrementing grade 150 (Too Low):" << std::endl;
		try {
			Bureaucrat intern("Intern", 150);
			std::cout << intern << std::endl;
			intern.decrementGrade();
			std::cout << "Error: Should not be printed" << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << "Caught expected exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 6: Copy & Assignment") << std::endl;
	{
		try {
			Bureaucrat original("Original", 42);
			std::cout << "Original: " << original << std::endl;

			// Copy Constructor
			Bureaucrat copy(original);
			std::cout << "Copy (via constructor): " << copy << std::endl;

			// Assignment Operator
			Bureaucrat assigned("Assigned", 100);
			std::cout << "Before assignment: " << assigned << std::endl;
			assigned = original;
			std::cout << "After assignment (from Original): " << assigned << std::endl;
			
			std::cout << "Note: Name should NOT change (const), only grade." << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Unexpected exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("All tests completed!") << std::endl;
	return 0;
}
