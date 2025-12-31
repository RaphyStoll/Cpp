#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "libftpp.hpp"
#include <iostream>

int main()
{
	std::cout << "\n" << pad_line("Test 1: Form Instantiation") << std::endl;
	{
		try {
			Form formA("FormA", 50, 100);
			std::cout << formA << std::endl;

			Form formB("FormB", 1, 1);
			std::cout << formB << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Unexpected exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 2: Form Instantiation (Exceptions)") << std::endl;
	{
		std::cout << "-> Creating Form with grade 0 (Too High):" << std::endl;
		try {
			Form form("TooHigh", 0, 100);
		}
		catch (std::exception &e) {
			std::cout << "Caught expected exception: " << e.what() << std::endl;
		}

		std::cout << "\n-> Creating Form with grade 151 (Too Low):" << std::endl;
		try {
			Form form("TooLow", 150, 151);
		}
		catch (std::exception &e) {
			std::cout << "Caught expected exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 3: Signing Forms (Success)") << std::endl;
	{
		try {
			Bureaucrat bob("Bob", 40);
			Form taxForm("Tax Form", 50, 100);

			std::cout << "Before sign: " << taxForm << std::endl;
			bob.signForm(taxForm);
			std::cout << "After sign: " << taxForm << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Unexpected exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 4: Signing Forms (Failure)") << std::endl;
	{
		try {
			Bureaucrat intern("Intern", 150);
			Form topSecret("Top Secret", 1, 1);

			std::cout << "Before sign: " << topSecret << std::endl;
			intern.signForm(topSecret); // Should fail
			std::cout << "After sign: " << topSecret << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Unexpected exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n" << pad_line("Test 5: Deep Copy") << std::endl;
	{
		Form original("Original", 42, 42);
		Bureaucrat boss("Boss", 1);
		boss.signForm(original);

		Form copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
		
		std::cout << "Note: Signed status should be copied." << std::endl;
	}

	std::cout << "\n" << pad_line("All tests completed!") << std::endl;
	return 0;
}
