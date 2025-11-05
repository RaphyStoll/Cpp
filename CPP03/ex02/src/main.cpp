#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== DIAMONDTRAP TEST ===" << std::endl;
    DiamondTrap d("Raph");
    d.whoAmI();
    d.attack("badguy");
    d.takeDamage(20);
    d.beRepaired(10);
    d.highFivesGuys();
    d.guardGate();

    std::cout << "\nTesting copy and assignment" << std::endl;
    DiamondTrap copy(d);
    copy.whoAmI();
    DiamondTrap assigned("Tmp");
    assigned = d;
    assigned.whoAmI();

    return 0;
}
