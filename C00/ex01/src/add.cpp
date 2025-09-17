#include "contact.hpp"
#include "contact.hpp"
#include <iostream>

static void sequence(Contact& contact,
		void (Contact::*setter)(const std::string&),
		const std::string& prompt);

void add(const Contact& contact)
{
	Contact cpy = Contact(contact);
	std::string line;

	std::getline(std::cin, line);
	
	sequence(cpy, &Contact::setFirstName, "ADD: first name : ");
	sequence(cpy, &Contact::setLastName, "ADD: last name : ");
	sequence(cpy, &Contact::setNickName, "ADD: nick name : ");
	sequence(cpy, &Contact::setPhoneNumber, "ADD: phone number : ");
	sequence(cpy, &Contact::setDarkestSecret, "Add: darkest secret : ");
	
	std::cout << "=== Contact added ===" << std::endl;
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
