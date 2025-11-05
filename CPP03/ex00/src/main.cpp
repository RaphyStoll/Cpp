#include "ClapTrap.hpp"
#include <iostream>

/**
 * @brief Teste basique des fonctionnalites de ClapTrap
 * 
 */
void test_basic_functions() {
	std::cout << "\n=== TEST 1: Basic Functions ===" << std::endl;
	
	ClapTrap clap("Bob");
	
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	std::cout << std::endl;
}

/**
 * @brief Teste l'epuisement de l'energie
 * 
 */
void test_energy_depletion() {
	std::cout << "\n=== TEST 2: Energy Depletion ===" << std::endl;
	
	ClapTrap clap("Alice");
	
	// Utiliser toute l'energie (10 actions)
	for (int i = 0; i < 10; i++) {
		clap.attack("dummy");
	}
	
	// Tenter d'attaquer sans energie
	std::cout << "\nTrying to attack with no energy:" << std::endl;
	clap.attack("another_target");
	
	// Tenter de se reparer sans energie
	std::cout << "\nTrying to repair with no energy:" << std::endl;
	clap.beRepaired(5);
	
	std::cout << std::endl;
}

/**
 * @brief Teste la mort du ClapTrap
 * 
 */
void test_death() {
	std::cout << "\n=== TEST 3: Death ===" << std::endl;
	
	ClapTrap clap("Charlie");
	
	// Infliger des degats mortels
	std::cout << "\nInflicting fatal damage:" << std::endl;
	clap.takeDamage(15);
	
	// Tenter d'attaquer alors qu'il est mort
	std::cout << "\nTrying to attack while dead:" << std::endl;
	clap.attack("ghost");
	
	// Tenter de se reparer alors qu'il est mort
	std::cout << "\nTrying to repair while dead:" << std::endl;
	clap.beRepaired(5);
	
	std::cout << std::endl;
}

/**
 * @brief Teste les constructeurs de copie et d'assignation
 * 
 */
void test_copy_and_assignment() {
	std::cout << "\n=== TEST 4: Copy and Assignment ===" << std::endl;
	
	ClapTrap clap1("Original");
	clap1.takeDamage(3);
	
	// Test constructeur de copie
	std::cout << "\nCopy constructor:" << std::endl;
	ClapTrap clap2(clap1);
	
	// Test operateur d'assignation
	std::cout << "\nAssignment operator:" << std::endl;
	ClapTrap clap3("ToBeReplaced");
	clap3 = clap1;
	
	std::cout << "\nTesting copied ClapTraps:" << std::endl;
	clap2.attack("test");
	clap3.beRepaired(2);
	
	std::cout << std::endl;
}

/**
 * @brief Teste le comportement avec des degats partiels
 * 
 */
void test_partial_damage() {
	std::cout << "\n=== TEST 5: Partial Damage and Repair ===" << std::endl;
	
	ClapTrap clap("David");
	
	// Infliger des degats progressifs
	clap.takeDamage(3);
	clap.takeDamage(2);
	clap.beRepaired(4);
	clap.takeDamage(1);
	clap.attack("enemy");
	
	std::cout << std::endl;
}

/**
 * @brief Teste le comportement avec des degats excessifs
 * 
 */
void test_excessive_damage() {
	std::cout << "\n=== TEST 6: Excessive Damage ===" << std::endl;
	
	ClapTrap clap("Eve");
	
	// Infliger plus de degats que de HP
	std::cout << "\nInflicting 100 damage to ClapTrap with 10 HP:" << std::endl;
	clap.takeDamage(100);
	
	std::cout << std::endl;
}

/**
 * @brief Teste la reparation excessive
 * 
 */
void test_excessive_repair() {
	std::cout << "\n=== TEST 7: Excessive Repair ===" << std::endl;
	
	ClapTrap clap("Frank");
	
	clap.takeDamage(5);
	std::cout << "\nRepairing for 50 HP (no max limit):" << std::endl;
	clap.beRepaired(50);
	
	std::cout << std::endl;
}

int main(void) {
	std::cout << "╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║     CLAPTRAP COMPREHENSIVE TESTS      ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝" << std::endl;
	
	test_basic_functions();
	test_energy_depletion();
	test_death();
	test_copy_and_assignment();
	test_partial_damage();
	test_excessive_damage();
	test_excessive_repair();
	
	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║          ALL TESTS COMPLETED           ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;
	
	return 0;
}