#pragma once
#include <iostream>
#include "weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon; // peut être NULL
	public:
		HumanB(const std::string& name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack() const;
};
