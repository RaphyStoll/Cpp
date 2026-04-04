#include "libftpp.hpp"
#include <exception>
#include <vector> 

class PmergeMe {
	private:
		std::vector<int> _v;
		libftpp::debug::DebugLogger _logger;
		int _size;

		bool is_sorted(const std::vector<int> &vct);
		void Merge_sort(std::vector<int> vct);
		void print_vector();
		bool init_vector(int argc,char **argv);
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

		std::vector<int> get_v();
		int get_size();
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