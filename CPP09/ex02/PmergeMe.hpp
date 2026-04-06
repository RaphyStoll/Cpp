#include "libftpp.hpp"
#include <exception>
#include <iostream>
#include <vector> 

class PmergeMe {
	private:
		std::vector<int> _v;
		libftpp::debug::DebugLogger _logger;
		int _size;
		libftpp::time::timestamp_us_t _start_time;
		libftpp::time::timestamp_us_t _end_time;

		bool init_vector(int argc,char **argv);
		void Merge_sort(std::vector<int> vct);

		bool is_sorted(const std::vector<int> &vct);
		void print_vector();

		template <typename T>
		void print_time(const T &inspected)
		{
			std::cout	<< "Time to process a range of "
						<< get_size()
						<< " elements with " << libftpp::meta::TypeInspector::name(inspected) << " : "
						<< libftpp::time::Clock::elapsed_compact_since_us(_start_time) << std::endl;
		}
	public:
		PmergeMe(int argv, char **tab); 
		~PmergeMe() {};
		PmergeMe(const PmergeMe& other) : _v(other._v), _logger(other._logger) {};
		PmergeMe& operator=(const PmergeMe& other) {
			if (this != &other) {
				_v = other._v;
				_logger = other._logger;
			}
			return *this;
		}
		libftpp::time::timestamp_us_t get_start_size() { return  this->_start_time;};
		libftpp::time::timestamp_us_t get_end_time() { return this->_end_time;};
		std::vector<int> get_v() { return this->_v;};
		int get_size() { return this->_size;};
		
		void run();

	class ParseError : public std::exception {
		public:
		virtual const char *what () const throw();
	};
	class NotSorted : public std::exception {
		public:
		virtual const char *what () const throw();
	};
	class StartSorted : public std::exception {
		public:
		virtual const char *what () const throw();
	};
};