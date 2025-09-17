#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
	private :
		Contact	contact[8];
		int		count; // conteur de plage pleine 1 -> 8
		int		next; //index 0 -> 7
	public :
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		PhoneBook& operator=(const PhoneBook phoneBook); //Right-Hand Side ou celui qu'on modifie (standard)
		~PhoneBook();

	void add(const Contact& contact);
	int  size() const;
	void exitProgram();

	void incrementCount();
	int findByFirstName(const std::string& name) const;
    int findByLastName(const std::string& name) const;
    int findByNickName(const std::string& name) const;

};

#endif