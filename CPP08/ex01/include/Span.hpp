#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <climits>

class Span {
    public:
        Span(unsigned int N);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &assign);

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        template <typename It>
        void addNumbers(It begin, It end)
        {
            while (begin != end)
            {
                addNumber(*begin);
                ++begin;
            }
        }

    private:
		unsigned int _maxSize;
        std::vector<int> _numbers;
};

#endif