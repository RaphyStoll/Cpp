#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &x) {
    std::cout << x << std::endl;
}

int main()
{
    int tab[] = { 0, 1, 2, 3, 4 };
    
    ::iter(tab, 5, print<int>);

    std::string strTab[] = { "caca", "prout", "bipbipbipbiiiipbiiipbiiipbipbipbip" };

    ::iter(strTab, 3, print<std::string>);
    
    return 0;
}
