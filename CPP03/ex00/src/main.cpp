#include "ClapTrap.hpp"
#include <iostream>
#include <string>

static std::string pad_line(const std::string& title) {
    std::string line;
    line += "+";
    line += std::string(38, '-');
    line += "+";
    std::string header = line + "\n";
    header += "| ";
    header += title;
    if (title.size() < 36) header += std::string(36 - title.size(), ' ');
    header += " |";
    header += "\n";
    header += line;
    return header;
}

int main()
{
    std::cout << std::endl;
    std::cout << pad_line("CLAPTRAP TEST") << std::endl;

    ClapTrap c("Robo");

    std::cout << std::endl;
    std::cout << pad_line("BASIC ACTIONS") << std::endl;
    std::cout << "-> attack() :" << std::endl;
    c.attack("target");
    std::cout << "-> takeDamage(5) :" << std::endl;
    c.takeDamage(5);
    std::cout << "-> beRepaired(3) :" << std::endl;
    c.beRepaired(3);

    std::cout << std::endl;
    std::cout << pad_line("ENERGY DEPLETION") << std::endl;
    ClapTrap energy_test("Alice");
    for (int i = 0; i < 10; i++) {
        energy_test.attack("dummy");
    }
    std::cout << "-> Trying to attack with no energy:" << std::endl;
    energy_test.attack("target");

    std::cout << std::endl;
    std::cout << pad_line("DEATH TEST") << std::endl;
    ClapTrap death_test("Charlie");
    std::cout << "-> takeDamage(15) :" << std::endl;
    death_test.takeDamage(15);
    std::cout << "-> Trying to attack while dead:" << std::endl;
    death_test.attack("ghost");

    std::cout << std::endl;
    std::cout << pad_line("COPY & ASSIGNMENT") << std::endl;
    std::cout << "- Copy constructor:" << std::endl;
    ClapTrap copy(c);

    std::cout << "- Assignment operator:" << std::endl;
    ClapTrap assigned("Tmp");
    assigned = c;

    std::cout << std::endl;
    std::cout << "All ClapTrap tests completed." << std::endl;
    std::cout << std::endl;
    return 0;
}