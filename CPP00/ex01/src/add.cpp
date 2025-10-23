#include "contact.hpp"
#include "phonebook.hpp"
#include "debug.hpp"
#include <iostream>
#include <sstream>

static void sequence(Contact& contact,
		void (Contact::*setter)(const std::string&),
		const std::string& prompt);

/**
 * @brief fonction qui demande a l'user de rentrer les info de contact
 * et ajoute a contact[8] sur un idex libre ou le plus vieux index
 * 
 * @param contact class contact qui pocede tout ce qui est en lien avec
 */
void PhoneBook::add()
{
	Contact cpy;
	
	sequence(cpy, &Contact::setFirstName, "ADD: first name : ");
	sequence(cpy, &Contact::setLastName, "ADD: last name : ");
	sequence(cpy, &Contact::setNickName, "ADD: nick name : ");
	sequence(cpy, &Contact::setPhoneNumber, "ADD: phone number : ");
	sequence(cpy, &Contact::setDarkestSecret, "Add: darkest secret : ");
	//system("clear");

	int slot = this->next;                 // emplacement physique d'insertion
	this->contact[slot] = cpy;             // écriture dans le slot courant
	if (this->count < 8)
		this->count++;                      // augmente le nombre réel de contacts jusqu'à 8
	this->next = (this->next + 1) % 8;     // prépare le prochain slot (circulaire)

	std::ostringstream build_msg;
	build_msg << "=== Contact \""
		<< cpy.getFirstName()
		<< " "
		<< cpy.getLastName()
		<< "\" stored at slot [" << slot << "]"
		<< " added ===";
	print_debug(build_msg.str());
}

static void sequence(Contact& contact,
		void (Contact::*setter)(const std::string&),
		const std::string& prompt)
{
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    (contact.*setter)(line);
}
