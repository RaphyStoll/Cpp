#include "Span.hpp"
#include <numeric>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw NoSpanFoundException();
    }
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int diff = sorted[i+1] - sorted[i];
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw NoSpanFoundException();
    }
    
    std::vector<int>::const_iterator minElem = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxElem = std::max_element(_numbers.begin(), _numbers.end());
    
    return *maxElem - *minElem;
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is already full. Cannot add more elements.";
}

const char* Span::NoSpanFoundException::what() const throw() {
    return "Not enough elements to find a span.";
}
