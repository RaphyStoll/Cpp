#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

/**
 * @class ScavTrap
 * @brief Robot dérivé de ClapTrap avec des caractéristiques différentes
 *
 * ScavTrap réutilise les attributs de ClapTrap mais initialise des valeurs
 * par défaut différentes (HP, énergie, dégâts) et ajoute la capacité
 * `guardGate()`.
 */
class ScavTrap : virtual public ClapTrap {
	protected:
		static const unsigned int	_default_hit_points = 100;
		static const unsigned int	_default_energy_points = 100;
		static const unsigned int	_default_attack_damage = 30;
	public:
		// Constructeur avec nom
		ScavTrap(const std::string& name);

		// Constructeur de copie
		ScavTrap(const ScavTrap& other);

		// Opérateur d'assignation
		ScavTrap& operator=(const ScavTrap& other);

		// Destructeur
		~ScavTrap();

		// Attaque redéfinie pour ScavTrap (affiche un message spécifique)
		void attack(const std::string& target);

		// Active le mode Gate keeper
		void guardGate();
};

#endif
