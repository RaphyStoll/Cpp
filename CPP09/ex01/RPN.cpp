#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::performOperation(char op) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error");
    }

    int v2 = _stack.back();
    _stack.pop_back();
    int v1 = _stack.back();
    _stack.pop_back();

    int result = 0;
    switch (op) {
        case '+': result = v1 + v2; break;
        case '-': result = v1 - v2; break;
        case '*': result = v1 * v2; break;
        case '/': 
            if (v2 == 0) throw std::runtime_error("Error"); 
            result = v1 / v2; 
            break;
    }
    _stack.push_back(result);
}

void RPN::calculate(const std::string& expression) {
    try {
        std::istringstream iss(expression);
        std::string token;

        while (iss >> token) {
            if (token.length() == 1 && isOperator(token[0])) {
                performOperation(token[0]);
            } else if (token.length() == 1 && isdigit(token[0])) {
                _stack.push_back(token[0] - '0');
            } else {
                throw std::runtime_error("Error");
            }
        }

        if (_stack.size() != 1) {
            throw std::runtime_error("Error");
        }

        std::cout << _stack.back() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
    }
}
