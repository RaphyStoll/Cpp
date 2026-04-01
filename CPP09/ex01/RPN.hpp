#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

class RPN {
private:
    std::list<int> _stack; // Utilisation de std::list comme pile pour ne pas réutiliser std::map

    bool isOperator(char c) const;
    void performOperation(char op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void calculate(const std::string& expression);
};

#endif
