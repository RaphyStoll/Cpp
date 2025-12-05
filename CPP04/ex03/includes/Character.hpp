#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp" // Need full definition for AMateria* _inventory[4]

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria*   _inventory[4];
	int         _equippedCount; // Keep track of how many slots are filled

	// For unequipped Materias to prevent memory leaks
	// The prompt says "Occupez-vous des Materias laissées au sol par votre personnage comme vous le sentez."
	// A simple array with a fixed max size for dropped items.
	static const int MAX_FLOOR_MATERIAS = 100; // Arbitrary limit
	AMateria*   _floorMaterias[MAX_FLOOR_MATERIAS];
	int         _floorCount;

	void _initInventory();
	void _clearInventory();
	void _copyInventory(const Character& other);
	void _clearFloorMaterias();

public:
	Character(std::string const & name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	virtual ~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
