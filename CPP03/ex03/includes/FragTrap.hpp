#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {
protected:
		static const unsigned int	_default_hit_points = 100;
		static const unsigned int	_default_energy_points = 100;
		static const unsigned int	_default_attack_damage = 30;
public:
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void highFivesGuys(void);
};

#endif
