#include "libftpp.hpp"
#include <deque>
#include <exception>
#include <iostream>
#include <utility>
#include <vector>

class PmergeMe {
private:
  libftpp::debug::DebugLogger _logger;

  std::vector<int> _v;
  std::vector<std::pair<int, int> > _pairs;
  std::deque<int> _chain_deque;
  std::vector<int> _chain_vector;
  int _stash;

  libftpp::time::timestamp_us_t _start_time;
  libftpp::time::timestamp_us_t _end_time;

  bool init_vector(int argc, char **argv);
  void Merge_sort(std::vector<int> vct);

  //helper function
  bool create_pairs(const std::vector<int> &vct) {
    if (vct.size() < 2)
        return true;

    for (size_t i = 0; i < vct.size(); i += 2) {
        if (i + 1 < vct.size()) {
            // On met TOUJOURS le plus grand en premier
            if (vct[i] > vct[i + 1])
                _pairs.push_back(std::make_pair(vct[i], vct[i + 1]));
            else
                _pairs.push_back(std::make_pair(vct[i + 1], vct[i]));
        } else {
            _stash = vct[i];
        }
    }
    print_pairs(_logger);
    return true;
  }

  void sort_and_extract_chain() {
    std::sort(_pairs.begin(), _pairs.end());
    for (size_t i = 0; i < _pairs.size(); ++i)
      _chain_vector.push_back(_pairs[i].first);
    if (!_pairs.empty())
      _chain_vector.insert(_chain_vector.begin(), _pairs[0].second);
    print_pairs(_logger);
  }

  bool is_sorted(const std::vector<int> &vct) {
    if (vct.size() < 2)
      return true;
    for (size_t i = 1; i < vct.size(); ++i) {
      if (vct[i - 1] > vct[i]) {
        _logger << "isn't sorted = " << vct[i - 1] << ">" << vct[i]
                << std::endl;
        return false;
      }
    }
    return true;
  };

  template <typename Stream>
  void print_vector(Stream &os, const std::vector<int> &vct) {
    for (size_t i = 0; i < vct.size(); i++) {
        os << vct[i] << " ";
    }
    os << std::endl;
  };

  template <typename Stream>
  void print_pairs(Stream &os) {
    os << "Pairs: ";
    for (size_t i = 0; i < _pairs.size(); ++i) {
      os << "[" << _pairs[i].first << ", " << _pairs[i].second << "] ";
    }
    os << std::endl;
    if (_stash != -1) {
      os << "Stash: " << _stash << std::endl;
    }
  }
  
  // J(n) = J(n-1) + 2*J(n-2)
  size_t get_jacobsthal_number(size_t n) {
    static const size_t h_jacob[] = {
        0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365,
        2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525,
        699051, 1398101, 2796203, 5592405, 11184811, 22369621,
        44739243, 89478485, 178956971, 357913941, 715827883};

    size_t h_size = sizeof(h_jacob) / sizeof(h_jacob[0]);

    if (n < h_size) {
      return h_jacob[n];
    } else {
      size_t jN1 = h_jacob[h_size - 1];
      size_t jN2 = h_jacob[h_size - 2];
      size_t current = 0;

      for (size_t i = h_size; i <= n; ++i) {
        current = jN1 + 2 * jN2;
        jN2 = jN1;
        jN1 = current;
      }
      return current;
    }
  }

  bool check_duplicate_value(const std::vector<int> &vct) {
    if (vct.size() < 2)
      return true;
    for (size_t i = 1; i < vct.size(); ++i) {
      if (vct[i - 1] == vct[i]) {
        _logger << "duplicate value = " << vct[i - 1] << "=" << vct[i]
                << std::endl;
        return false;
      }
    }
    return true;
  };

  template <typename T> void print_time(const T &inspected) {
    std::cout << "Time to process a range of " << inspected.size()
              << " elements with "
              << libftpp::meta::TypeInspector::name(inspected) << " : "
              << libftpp::time::Clock::elapsed_compact_since_us(_start_time)
              << std::endl;
  }

public:
  PmergeMe(int argv, char **tab);
  ~PmergeMe() {};
  PmergeMe(const PmergeMe &other)
      : _logger(other._logger), _v(other._v), _pairs(other._pairs),
        _chain_deque(other._chain_deque), _chain_vector(other._chain_vector),
        _stash(other._stash), _start_time(other._start_time),
        _end_time(other._end_time) {};
  PmergeMe &operator=(const PmergeMe &other) {
    if (this != &other) {
      _logger = other._logger;
      _v = other._v;
      _pairs = other._pairs;
      _chain_deque = other._chain_deque;
      _chain_vector = other._chain_vector;
      _stash = other._stash;
      _start_time = other._start_time;
      _end_time = other._end_time;
    }
    return *this;
  }

  libftpp::time::timestamp_us_t get_start_size() const {
    return this->_start_time;
  };
  libftpp::time::timestamp_us_t get_end_time() const {
    return this->_end_time;
  };
  std::vector<int> get_v() const { return this->_v; };
  std::vector<std::pair<int, int> > get_pairs() const { return this->_pairs; };
  std::deque<int> get_chain_deque() const { return this->_chain_deque; };
  std::vector<int> get_chain_vector() const { return this->_chain_vector; };
  int get_stash() const { return this->_stash; };

  void run();

  class ParseError : public std::exception {
  public:
    virtual const char *what() const throw() { return "ERROR: Parsing error look logs"; };
  };
  class NotSorted : public std::exception {
  public:
    virtual const char *what() const throw() { return "ERROR: This isn't sorted"; };
  };
  class StartSorted : public std::exception {
  public:
    virtual const char *what() const throw() { return "It's sorted"; };
  };
};