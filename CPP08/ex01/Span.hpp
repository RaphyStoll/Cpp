#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
    
    Span(); 

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize) {
            throw SpanFullException();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;

    class SpanFullException : public std::exception {
        virtual const char* what() const throw();
    };

    class NoSpanFoundException : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif
