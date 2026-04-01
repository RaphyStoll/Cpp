#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::cout << "Testing with std::vector" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found value: " << *it << std::endl;
        
        it = easyfind(vec, 42);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTesting with std::list" << std::endl;
    std::list<int> lst;
    for (int i = 0; i < 5; ++i)
        lst.push_back(i * 10);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found value: " << *it << std::endl;
        
        it = easyfind(lst, 99);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
