#pragma once
#include <iostream>
#include "weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon &weapon; // référence: toujours armé
	public:
		HumanA(const std::string& name, Weapon &weapon);
		~HumanA();
		void attack() const;
};
