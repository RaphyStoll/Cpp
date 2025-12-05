#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name;

public:
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    // Utilise l'attaque de ScavTrap
    void attack(const std::string& target);

    // Affiche le nom DiamondTrap et le nom ClapTrap
    void whoAmI() const;
};

#endif
