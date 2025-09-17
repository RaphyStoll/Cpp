#include "contact.hpp"
/**
 * @brief toutes ces fonction sont des setter qui set une valeur a une autre
 * 
 * @param str string a copier
 */
void Contact::setFirstName(const std::string& str)
{
	this->first_name = str;
}

void Contact::setLastName(const std::string& str)
{
	this->last_name = str;
}

void Contact::setNickName(const std::string& str)
{
	this->nick_name = str;
}

void Contact::setPhoneNumber(const std::string& str)
{
	this->phone_number = str;
}

void Contact::setDarkestSecret(const std::string& str)
{
	this->darkest_secret = str;
}
