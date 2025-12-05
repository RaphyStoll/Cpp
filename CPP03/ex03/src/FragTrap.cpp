#include "FragTrap.hpp"
#include "debug.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap " << _name << " constructed! (HP: " << _hit_points
              << ", Energy: " << _energy_points << ", Attack: " << _attack_damage << ")" << std::endl;
    print_debug("FragTrap object created");
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " copied!" << std::endl;
    print_debug("FragTrap copy constructor called");
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << _name << " assigned!" << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destroyed!" << std::endl;
    print_debug("FragTrap object deleted");
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}
