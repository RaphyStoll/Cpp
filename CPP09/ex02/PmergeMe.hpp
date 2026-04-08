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

  void print_vector() {
    for (size_t i = 0; i < _v.size(); i++) {
      _logger << _v[i] << " ";
      std::cout << _v[i] << " ";
    }
    _logger << std::endl;
    std::cout << std::endl;
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
    virtual const char *what() const throw() {
      return "Parsing error look logs";
    };
  };
  class NotSorted : public std::exception {
  public:
    virtual const char *what() const throw() { return "this isn't sorted"; };
  };
  class StartSorted : public std::exception {
  public:
    virtual const char *what() const throw() { return "It's sorted"; };
  };
};