#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

Span::Span(const Span &copy) : _maxSize(copy._maxSize), _numbers(copy._numbers) {}

Span &Span::operator=(const Span &assign)
{
    if (this != &assign)
    {
        _maxSize = assign._maxSize;
        _numbers = assign._numbers;
    }
    return *this;
}

void Span::addNumber(int num)
{
    if (_numbers.size() >= _maxSize)
        throw std::overflow_error("Span is full");
    _numbers.push_back(num);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers");
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int minSpan = INT_MAX;
    for (size_t i = 1; i < sorted.size(); i++)
        minSpan = std::min(minSpan, sorted[i] - sorted[i-1]);
    
    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers");
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    
    return max - min;
}