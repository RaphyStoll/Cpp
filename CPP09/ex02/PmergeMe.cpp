#include "libftpp.hpp"
#include "PmergeMe.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <ostream>
#include <vector>

PmergeMe::PmergeMe(int argc, char **tab) : _logger("general")
{
	if (!init_vector(argc, tab))
		throw PmergeMe::ParseError();
	_size = _v.size();
	if (!is_sorted(get_v())) {
		_logger << "in constructor is sorted" << std::endl;
		throw PmergeMe::StartSorted(); 
	}
	std::cout << "before : ";
	print_vector();
}

int PmergeMe::get_size()
{
	return this->_size;
}

std::vector<int> PmergeMe::get_v()
{
	return this->_v;
}

bool PmergeMe::init_vector(int argc, char **tab)
{
	_logger << pad_line("init vector");
	for (int i = 1; i < argc; i++) {
		try {
			int a = libftpp::str::StringUtils::stoi(tab[i]);
			if (a < 0)
				return false;
			_v.push_back(a);
		}
		catch (std::invalid_argument &e) {
			_logger << "argv[" << i << "] = " << "'" << tab[i] << "'" << " is invalid" << std::endl;
			return false;
		}
		catch (std::out_of_range &e) {
			std::cerr << "out of range int MIN|MAX" << std::endl;
			return false;
		}
	}
	return true;
}

void PmergeMe::print_vector()
{
	for(size_t i = 0; i < _v.size(); i++) {
		_logger << _v[i] << " ";
		std::cout << _v[i] << " ";
	}
	_logger << std::endl;
	std::cout << std::endl;
}

bool PmergeMe::is_sorted(const std::vector<int> &vct)
{
	if (vct.size() < 2)
		return true;
	for (size_t i = 1; i < vct.size(); ++i) {
		if (vct[i - 1] > vct[i]) {
			_logger << "isn't sorted = " << vct[i - 1] << ">" << vct[i] << std::endl;
			return false;
		}
	}
	return true;
}

void PmergeMe::Merge_sort(std::vector<int> vct){

	if(!PmergeMe::is_sorted(vct))
		throw PmergeMe::NotSorted();
	_logger << "sorted" << std::endl;
}

void PmergeMe::run()
{
	PmergeMe::Merge_sort(PmergeMe::get_v());
	std::cout << "after : ";
	PmergeMe::print_vector();
	return;
}


const char *PmergeMe::ParseError::what() const throw()
{
	return "Parsing error look logs";
}

const char *PmergeMe::NotSorted::what() const throw()
{
	return "this isn't sorted";
}

const char *PmergeMe::StartSorted::what() const throw()
{
	return "It's sorted";
}