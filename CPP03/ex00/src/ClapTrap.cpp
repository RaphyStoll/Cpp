#include "ClapTrap.hpp"
#include "debug.hpp"
#include <iostream>

/**
 * @brief Constructeur
 *
 * Initialise le ClapTrap avec un nom et les valeurs par défaut :
 * hit points = 10, energy points = 10, attack damage = 0.
 *
 * @param name nom du ClapTrap
 */
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap " << _name << " constructed! (HP: " << _hit_points 
			  << ", Energy: " << _energy_points << ", Attack: " << _attack_damage << ")" << std::endl;
	print_debug("ClapTrap object created");
}

/**
 * @brief Destructeur
 */
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
	print_debug("ClapTrap object deleted");
}

/**
 * @brief Constructeur de copie
 *
 * Copie tous les attributs de l'autre ClapTrap.
 *
 * @param other ClapTrap source
 */
ClapTrap::ClapTrap(const ClapTrap& other)  m : _name(other._name), _hit_points(other._hit_points), 
	  _energy_points(other._energy_points), _attack_damage(other._attack_damage) {
	std::cout << "ClapTrap " << _name << " copied!" << std::endl;
	print_debug("ClapTrap copy constructor called");
}

/**
 * @brief Opérateur d'assignation
 * 
 * Copie les attributs depuis `other` si ce n'est pas la même instance.
 */
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	print_debug("ClapTrap assignment operator called");
	if (this != &other) {
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
		std::cout << "ClapTrap " << _name << " assigned!" << std::endl;
	}
	return *this;
}

/**
 * @brief Attaque une cible (coûte 1 point d'énergie)
 *
 * Ne fait rien si le ClapTrap est mort (HP == 0) ou sans énergie.
 *
 * @param target nom de la cible
 */
void ClapTrap::attack(const std::string& target) {
	// Vérifier si le ClapTrap est mort
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
		return;
	}
    
	// Vérifier si le ClapTrap a assez d'énergie
	if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " has no energy left and can't attack!" << std::endl;
		return;
	}
    
	// Attaquer
	_energy_points--;
	std::cout << "ClapTrap " << _name << " attacks " << target 
			  << ", causing " << _attack_damage << " points of damage! "
			  << "(Energy left: " << _energy_points << ")" << std::endl;
}

/**
 * @brief Inflige des dégâts au ClapTrap
 *
 * Réduit les hit points de `amount`. Gère le cas où `amount` est supérieur
 * aux HP actuels (HP mis à 0, pas de wrap-around avec unsigned).
 *
 * @param amount quantité de dégâts
 */
void ClapTrap::takeDamage(unsigned int amount) {
	// Éviter l'underflow avec unsigned int
	if (amount >= _hit_points) {
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount 
				  << " points of damage and is now dead! (HP: 0)" << std::endl;
	} else {
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount 
				  << " points of damage! (HP left: " << _hit_points << ")" << std::endl;
	}
}

/**
 * @brief Répare le ClapTrap (coûte 1 point d'énergie)
 *
 * Augmente les HP de `amount`. Ne fait rien si le ClapTrap est mort ou sans
 * énergie.
 *
 * @param amount quantité de HP à restaurer
 */
void ClapTrap::beRepaired(unsigned int amount) {
	// Vérifier si le ClapTrap est mort
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " is dead and can't repair itself!" << std::endl;
		return;
	}
    
	// Vérifier si le ClapTrap a assez d'énergie
	if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " has no energy left and can't repair itself!" << std::endl;
		return;
	}
    
	// Réparer
	_energy_points--;
	_hit_points += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
			  << " HP! (HP: " << _hit_points << ", Energy left: " << _energy_points << ")" << std::endl;
}