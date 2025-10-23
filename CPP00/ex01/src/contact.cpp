#include "contact.hpp"
#include "debug.hpp"
#include <iostream>

/**
 * @brief Construct a new Contact:: Contact object
 * 
 */
Contact::Contact(void) {
	print_debug("object Contact created");
}

/**
 * @brief Destroy the Contact:: Contact object
 * 
 */
Contact::~Contact(void) {
	print_debug("object Contact deleted");
}

/**
 * @brief Construct a new Contact:: Contact object
 * constructeur de copie
 * 
 * @param other 
 */
Contact::Contact(const Contact& other) {
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->nick_name = other.nick_name;
	this->phone_number = other.phone_number;
	this->darkest_secret = other.darkest_secret;
}

/**
 * @brief constructeur d'assignation
 * 
 * @param other autre classe(cpy) a assigner
 * @return Contact& main class
 */
Contact& Contact::operator=(const Contact& other) {
	if (this != &other) {
		this->first_name = other.first_name;
		this->last_name = other.last_name;
		this->nick_name = other.nick_name;
		this->phone_number = other.phone_number;
		this->darkest_secret = other.darkest_secret;
	}
	return *this;
}
