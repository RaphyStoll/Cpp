#include "PmergeMe.hpp"
#include "Clock.hpp"
#include "libftpp.hpp"

#include <climits>
#include <iostream>
#include <ostream>
#include <vector>

PmergeMe::PmergeMe(int argc, char **tab) : _logger("general") {
  if (!init_vector(argc, tab))
    throw PmergeMe::ParseError();
  if (is_sorted(_v)) {
    _logger << "in constructor is sorted" << std::endl;
    throw PmergeMe::StartSorted();
  }
  if (!check_duplicate_value(_v)) {
    _logger << "dobble value not accepted" << std::endl;
    throw PmergeMe::ParseError();
  }
  _stash = -1;
  _start_time = 0;
  _end_time = 0;
  std::cout << "before : ";
  print_vector(std::cout, _v);
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
  _logger << "initial vector : ";
  print_vector(_logger, _v);
  return true;
}

void PmergeMe::Merge_sort(std::vector<int> vct) {
  if (!PmergeMe::is_sorted(vct))
    throw PmergeMe::NotSorted();
  _logger << "merge sort sorted" << std::endl;
}


void PmergeMe::run() {
  _start_time = libftpp::time::Clock::now_us();
  create_pairs(_v, _pairs);
  sort_and_extract_chain(_chain_vector, _pairs);
  insert_remaining_elements(_chain_vector, _pairs);
  std::cout << std::endl;
  std::cout << "after : ";
  PmergeMe::print_vector(std::cout, _chain_vector);
  std::cout << std::endl;
  PmergeMe::print_time(_chain_vector, _start_time);
  _start_time = libftpp::time::Clock::now_us();
  sort_and_extract_chain(_chain_deque, _pairs);
  insert_remaining_elements(_chain_deque, _pairs);
  PmergeMe::print_time(_chain_deque, _start_time);
  return;
}
