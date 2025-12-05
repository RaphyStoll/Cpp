#include "ScavTrap.hpp"
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
    std::cout << pad_line("SCAVTRAP TEST") << std::endl;

    ScavTrap s("Guardian");

    std::cout << std::endl;
    std::cout << pad_line("ACTIONS") << std::endl;
    std::cout << "-> guardGate() :" << std::endl;
    s.guardGate();
    std::cout << "-> attack() :" << std::endl;
    s.attack("intruder");
    std::cout << "-> takeDamage(90) :" << std::endl;
    s.takeDamage(90);
    std::cout << "-> beRepaired(50) :" << std::endl;
    s.beRepaired(50);

    std::cout << std::endl;
    std::cout << pad_line("COPY & ASSIGNMENT") << std::endl;
    std::cout << "- Copy constructor:" << std::endl;
    ScavTrap copy(s);

    std::cout << "- Assignment operator:" << std::endl;
    ScavTrap assigned("Tmp");
    assigned = s;

    std::cout << std::endl;
    std::cout << pad_line("MULTIPLE SCAVTRAP") << std::endl;
    ScavTrap s1("Alpha");
    ScavTrap s2("Beta");
    s1.attack("enemy1");
    s2.attack("enemy2");
    s1.guardGate();
    s2.guardGate();

    std::cout << std::endl;
    std::cout << "All ScavTrap tests completed." << std::endl;
    std::cout << std::endl;
    return 0;
}
