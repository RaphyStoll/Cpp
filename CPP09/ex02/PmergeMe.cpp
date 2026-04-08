#include "PmergeMe.hpp"
#include "libftpp.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <ostream>
#include <vector>

PmergeMe::PmergeMe(int argc, char **tab) : _logger("general") {
  if (!init_vector(argc, tab))
    throw PmergeMe::ParseError();
  if (!is_sorted(get_v())) {
    _logger << "in constructor is sorted" << std::endl;
    throw PmergeMe::StartSorted();
  }
  if (!check_duplicate_value(get_v())) {
    _logger << "dobble value not accepted" << std::endl;
    throw PmergeMe::ParseError();
  }
  _start_time = libftpp::time::Clock::now_us();
  _end_time = 0;
  std::cout << "before : ";
  print_vector();
}

bool PmergeMe::init_vector(int argc, char **tab) {
  _logger << pad_line("init vector");
  for (int i = 1; i < argc; i++) {
    try {
      int a = libftpp::str::StringUtils::stoi(tab[i]);
      if (a < 0)
        return false;
      _v.push_back(a);
    } catch (std::invalid_argument &e) {
      _logger << "argv[" << i << "] = " << "'" << tab[i] << "'" << " is invalid"
              << std::endl;
      return false;
    } catch (std::out_of_range &e) {
      std::cerr << "out of range int MIN|MAX" << std::endl;
      return false;
    }
  }
  return true;
}

void PmergeMe::Merge_sort(std::vector<int> vct) {

  if (!PmergeMe::is_sorted(vct))
    throw PmergeMe::NotSorted();
  _logger << "sorted" << std::endl;
}

void PmergeMe::run() {
  PmergeMe::Merge_sort(PmergeMe::get_v());
  std::cout << "after : ";
  PmergeMe::print_vector();
  // Time to process a range of 5 elements with std::[..] : 0.00031 us
  PmergeMe::print_time(_v);
  return;
}
