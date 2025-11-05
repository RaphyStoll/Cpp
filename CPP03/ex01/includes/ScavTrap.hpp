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
class ScavTrap : public ClapTrap {
	public:
		/**
		 * @brief Constructeur avec nom
		 */
		ScavTrap(const std::string& name);

		/**
		 * @brief Constructeur de copie
		 */
		ScavTrap(const ScavTrap& other);

		/**
		 * @brief Opérateur d'assignation
		 */
		ScavTrap& operator=(const ScavTrap& other);

		/**
		 * @brief Destructeur
		 */
		~ScavTrap();

		/**
		 * @brief Attaque redéfinie pour ScavTrap (affiche un message spécifique)
		 */
		void attack(const std::string& target);

		/**
		 * @brief Active le mode Gate keeper
		 */
		void guardGate();
};

#endif
