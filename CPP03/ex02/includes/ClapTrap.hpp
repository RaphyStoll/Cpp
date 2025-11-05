#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

// === mini norm ===
// classe = UpperCamelCase
// fonction = CamelCase
// variable = snake_case

/**
 * @class ClapTrap
 * @brief Classe représentant un ClapTrap minimal
 *
 * Contient les attributs essentiels d'un ClapTrap (HP, énergie, dégâts)
 * et les opérations de base (attaque, subir des dégâts, réparation).
 */
class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	
	public:
		/**
		 * @brief Constructeur avec nom
		 * @param name nom du ClapTrap
		 */
		ClapTrap(const std::string& name);

		// Constructeur de copie
		ClapTrap(const ClapTrap& other);

		// Opérateur d'assignation
		ClapTrap& operator=(const ClapTrap& other);

		// Destructeur
		~ClapTrap();

		/**
		 * @brief Envoie une attaque sur la cible (coûte 1 énergie)
		 * @param target nom de la cible
		 */
		void attack(const std::string& target);

		/**
		 * @brief Inflige des dégâts au ClapTrap
		 * @param amount quantité de dégâts reçus
		 */
		void takeDamage(unsigned int amount);

		/**
		 * @brief Répare le ClapTrap (coûte 1 énergie)
		 * @param amount quantité de PV restaurés
		 */
		void beRepaired(unsigned int amount);
};

#endif