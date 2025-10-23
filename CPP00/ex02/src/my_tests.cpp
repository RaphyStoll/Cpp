#include <iostream>
#include "Account.hpp"

int main(void) {
	std::cout << "=== Test personnalisé de la classe Account ===" << std::endl;
	std::cout << std::endl;
	
	// Test 1: Création de comptes
	std::cout << "Test 1: Création de comptes" << std::endl;
	Account acc1(100);
	Account acc2(200);
	Account acc3(0);
	std::cout << std::endl;
	
	// Test 2: Affichage des informations globales
	std::cout << "Test 2: Informations globales" << std::endl;
	Account::displayAccountsInfos();
	std::cout << std::endl;
	
	// Test 3: Affichage du statut de chaque compte
	std::cout << "Test 3: Statut de chaque compte" << std::endl;
	acc1.displayStatus();
	acc2.displayStatus();
	acc3.displayStatus();
	std::cout << std::endl;
	
	// Test 4: Dépôts
	std::cout << "Test 4: Dépôts" << std::endl;
	acc1.makeDeposit(50);
	acc2.makeDeposit(100);
	acc3.makeDeposit(25);
	std::cout << std::endl;
	
	// Test 5: Informations après dépôts
	std::cout << "Test 5: Informations après dépôts" << std::endl;
	Account::displayAccountsInfos();
	acc1.displayStatus();
	acc2.displayStatus();
	acc3.displayStatus();
	std::cout << std::endl;
	
	// Test 6: Retraits (succès et échec)
	std::cout << "Test 6: Retraits" << std::endl;
	acc1.makeWithdrawal(25);   // Succès
	acc2.makeWithdrawal(500);  // Échec (montant insuffisant)
	acc3.makeWithdrawal(10);   // Succès
	std::cout << std::endl;
	
	// Test 7: Informations finales
	std::cout << "Test 7: Informations finales" << std::endl;
	Account::displayAccountsInfos();
	acc1.displayStatus();
	acc2.displayStatus();
	acc3.displayStatus();
	std::cout << std::endl;
	
	// Test 8: Getters statiques
	std::cout << "Test 8: Vérification des getters statiques" << std::endl;
	std::cout << "Nombre de comptes: " << Account::getNbAccounts() << std::endl;
	std::cout << "Montant total: " << Account::getTotalAmount() << std::endl;
	std::cout << "Nombre de dépôts: " << Account::getNbDeposits() << std::endl;
	std::cout << "Nombre de retraits: " << Account::getNbWithdrawals() << std::endl;
	std::cout << std::endl;
	
	std::cout << "=== Fin des tests (destructeurs à venir) ===" << std::endl;
	return 0;
}
