#include "DiamondTrap.hpp"
#include "debug.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    // Ajuster les valeurs : HP de FragTrap, energy de ScavTrap, attack de FragTrap
    _hit_points = FragTrap::_hit_points;
    _energy_points = ScavTrap::_energy_points;
    _attack_damage = FragTrap::_attack_damage;

    std::cout << "DiamondTrap " << _name << " constructed! (HP: " << _hit_points
              << ", Energy: " << _energy_points << ", Attack: " << _attack_damage << ")" << std::endl;
    print_debug("DiamondTrap object created");
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap " << _name << " copied!" << std::endl;
    print_debug("DiamondTrap copy constructor called");
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
        std::cout << "DiamondTrap " << _name << " assigned!" << std::endl;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
    print_debug("DiamondTrap object deleted");
}

void DiamondTrap::attack(const std::string& target)
{
    // Utiliser explicitement ScavTrap::attack pour lever toute ambiguïté
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const
{
    std::cout << "I am DiamondTrap '" << _name << "', ClapTrap name is '" << ClapTrap::_name << "'" << std::endl;
}
