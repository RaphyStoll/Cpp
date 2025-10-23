#include "contact.hpp"
#include <iostream>
/**
 * @brief toutes ces fonctions sont des getter qui vont chercher une info
 * 
 * @return const std::string& l'info chercher
 */
const std::string& Contact::getFirstName() const {
	return this->first_name;
}

const std::string& Contact::getLastName() const {
	return this->last_name;
}

const std::string& Contact::getNickName() const {
	return this->nick_name;
}

const std::string& Contact::getPhoneNumber() const {
	return this->phone_number;
}

const std::string& Contact::getDarkestSecret() const {
	return this->darkest_secret;
}
