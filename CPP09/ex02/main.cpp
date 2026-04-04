#include "PmergeMe.hpp"


#include <exception>
#include <iostream>
#include <ostream>


//map et list interdit

// bool parse_arg(char **argv)
// {}

// MACOS ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
// Linux ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
int main (int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error usage: ./PmergeMe <arg1> <...>" << std::endl;
		return 1;
	}
	try{
		PmergeMe Pmerge(argc, argv);
		Pmerge.run();
	}
	catch (PmergeMe::ParseError &e) {
		std::cerr << e.what() << std::endl;
		return 2;
	}
	catch (PmergeMe::NotSorted &e) {
		std::cerr << e.what() << std::endl;
		return 3;
	}
	catch (PmergeMe::StartSorted &e) {
		return 0;
	}
	catch (std::exception &e) {
		std::cerr << "Please use a more specific exception" << std::endl;
		return 1;
	}
	return 0;
}