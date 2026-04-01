#include <iostream>
#include "Span.hpp"
#include <vector>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    Span sp2(10000);
    std::vector<int> lotsOfNumbers;
    for (int i = 0; i < 10000; ++i) {
        lotsOfNumbers.push_back(i * 2);
    }
    sp2.addNumber(lotsOfNumbers.begin(), lotsOfNumbers.end());
    std::cout << "\nLarge Span (10000 elements):" << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    return 0;
}
