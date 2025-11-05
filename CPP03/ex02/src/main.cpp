#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

// Helper compatible C++98 pour afficher un en-tête décoré
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
    std::cout << pad_line("DIAMONDTRAP TEST") << std::endl;

    DiamondTrap d("Popo");

    std::cout << std::endl;
    std::cout << pad_line("IDENTITY") << std::endl;
    d.whoAmI();

    std::cout << std::endl;
    std::cout << pad_line("ACTIONS") << std::endl;
    std::cout << "-> attack() :" << std::endl;
    d.attack("badguy");
    std::cout << "-> takeDamage(20) :" << std::endl;
    d.takeDamage(20);
    std::cout << "-> beRepaired(10) :" << std::endl;
    d.beRepaired(10);
    std::cout << "-> highFivesGuys() :" << std::endl;
    d.highFivesGuys();
    std::cout << "-> guardGate() :" << std::endl;
    d.guardGate();

    std::cout << std::endl;
    std::cout << pad_line("COPY & ASSIGNMENT") << std::endl;
    std::cout << "- Copy constructor:" << std::endl;
    DiamondTrap copy(d);
    copy.whoAmI();

    std::cout << "- Assignment operator:" << std::endl;
    DiamondTrap assigned("Tmp");
    assigned = d;
    assigned.whoAmI();

    std::cout << std::endl;
    std::cout << "All DiamondTrap tests completed." << std::endl;
    std::cout << std::endl;
    return 0;
}
