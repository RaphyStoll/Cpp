#include "phonebook.hpp"
#include <iostream>

void print_debug(std::string str);

PhoneBook::PhoneBook(void) {
	this->count = 1;
	this->next = 0;
	print_debug("object PhoneBook created");
}

PhoneBook::~PhoneBook(void) {
	print_debug("object PhoneBook deleted");
}

PhoneBook::PhoneBook(const PhoneBook& other) {
	for (int i = 0; i < 8; i++)
		this->contact[i] = other.contact[i];
	this->count = other.count;
	this->next = other.next;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
	if (this != &other) {
		for (int i = 0; i < 8; i++)
			this->contact[i] = other.contact[i];
		this->count = other.count;
		this->next = other.next;
	}
	return *this;
}
