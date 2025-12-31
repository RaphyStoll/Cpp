#include "ScalarConverter.hpp"
#include "libftpp.hpp"
#include <iostream>
#include <string>

static void runTest(const std::string &literal)
{
	std::cout << std::endl << pad_line("Test: " + literal) << std::endl;
	ScalarConverter::convert(literal);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << pad_line("RUNNING DEFAULT TESTS") << std::endl;

		// Char tests
		runTest("a");
		runTest("*");
		
		// Int tests
		runTest("0");
		runTest("-42");
		runTest("42");
		runTest("2147483647");
		runTest("-2147483648");

		// Float tests
		runTest("0.0f");
		runTest("4.2f");
		runTest("-4.2f");
		runTest("inff");
		runTest("-inff");
		runTest("nanf");

		// Double tests
		runTest("0.0");
		runTest("4.2");
		runTest("-4.2");
		runTest("inf");
		runTest("-inf");
		runTest("nan");

		// Edge cases / Impossible
		runTest("impossible");
		runTest("2147483648"); // Int overflow -> double
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			runTest(argv[i]);
		}
	}

	return 0;
}
