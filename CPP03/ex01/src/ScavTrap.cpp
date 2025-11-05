#include "ScavTrap.hpp"
#include "debug.hpp"
#include <iostream>

/**
 * @brief Constructeur
 *
 * Appelle le constructeur de ClapTrap puis adapte les attributs pour
 * ScavTrap : HP=100, Energy=50, Attack=20
 */
ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " constructed! (HP: " << _hit_points
			  << ", Energy: " << _energy_points << ", Attack: " << _attack_damage << ")" << std::endl;
	print_debug("ScavTrap object created");
}

/**
 * @brief Constructeur de copie
 */
ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copied!" << std::endl;
	print_debug("ScavTrap copy constructor called");
}

/**
 * @brief Operateur d'assignation
 */
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "ScavTrap " << _name << " assigned!" << std::endl;
	}
	return *this;
}

/**
 * @brief Destructeur
 */
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
	print_debug("ScavTrap object deleted");
}

/**
 * @brief Attaque redéfinie pour ScavTrap
 */
void ScavTrap::attack(const std::string& target)
{
	if (_hit_points == 0) {
		std::cout << "ScavTrap " << _name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (_energy_points == 0) {
		std::cout << "ScavTrap " << _name << " has no energy left and can't attack!" << std::endl;
		return;
	}
	_energy_points--;
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attack_damage << " points of damage! "
			  << "(Energy left: " << _energy_points << ")" << std::endl;
}

/**
 * @brief Active le mode Gate keeper
 */
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

