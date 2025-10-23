#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include "debug.hpp"
#include <iostream>


class PhoneBook {
	private :
		Contact	contact[8];
		int		count; // nbr index full (1 - 8)
		int		next; // prochain index libre (0 - 8)
	public :
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		PhoneBook& operator=(const PhoneBook& other);
		~PhoneBook();

	void add();
	int  search() const;
	void exitProgram();

	int findByFirstName(const std::string& name) const;
	int findByLastName(const std::string& name) const;
	int findByNickName(const std::string& name) const;

};

#endif