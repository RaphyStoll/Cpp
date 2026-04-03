#include "PmergeMe.hpp"
#include "../../LIBFTPP/include/libftpp.hpp"

#include <iostream>
#include <vector>


// bool parse_arg(char **argv)
// {}
void print_list(std::vector<int>& x, libftpp::debug::DebugLogger& _logger)
{
	for(unsigned int i = 0; i < x.size(); i++) {
		_logger << x[i] << " ";
		std::cout << x[i] << " ";
	}
	_logger << "EOF" << std::endl;
	std::cout << "EOF" << std::endl;
}

int main (int argc, char **argv)
{
	libftpp::debug::DebugLogger _logger("log");
	logger l;
	if (argc < 2) {
		_logger << "ERROR: argc < 2 need a argument" << std::endl;
		std::cerr << "Error usage: ./PmergeMe <arg1> <...>" << std::endl;
		return 1;
	}
	std::vector<int> v;
	for (unsigned int i = 1; i < (unsigned int)argc; i++) {
		try {
			_logger << libftpp::str::StringUtils::pad
			v.push_back(libftpp::str::StringUtils::stoi(argv[i]));
		}
		catch (std::invalid_argument &e) {
			_logger << argv[i] << " is invalid" << std::endl;
			std::cerr << "Arg invalid" << std::endl;
		}
		catch (std::out_of_range &e) {
			std::cerr << "out of range int MIN|MAX" << std::endl;
			return 1;
		}
	}
	
	print_list(v, _logger);

	return 0;
}