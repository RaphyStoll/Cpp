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

	this->contact[this->count] = cpy;
	if (this->count < 8)
		this->count += 1;
	int stored = this->next;
	this->next = (this->next + 1) % 8;
	
	std::ostringstream build_msg; 
	build_msg << "=== Contact \""
		<< cpy.getFirstName()
		<< " " 
		<< cpy.getLastName()
		<< "\" stored at slot [" << stored << "]"
		<< " added ===";
	std::string msg = build_msg.str();
	print_debug(msg);
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
