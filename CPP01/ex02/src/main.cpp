#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "Adresse de brain        : " << &brain << std::endl;
    std::cout << "Adresse via stringPTR   : " << stringPTR << std::endl;
    std::cout << "Adresse via stringREF   : " << &stringREF << std::endl;

    std::cout << "Valeur de brain         : " << brain << std::endl;
    std::cout << "Valeur *stringPTR       : " << *stringPTR << std::endl;
    std::cout << "Valeur stringREF        : " << stringREF << std::endl;

    return 0;
}