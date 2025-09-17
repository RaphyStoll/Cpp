#include <iostream>
#include <cstdlib>
#include "phonebook.hpp"

static void inti();
static bool switch_case(PhoneBook& pb,Contact& contact, const std::string line);

int main ()
{
	bool flag = false;
	std::string line;
	PhoneBook pb;
	Contact cpy;

	if (!flag)
	{
		system("clear");
		flag = true;
	}
		inti();
		std::getline(std::cin, line);
		if (!switch_case(pb, cpy, line))
			main();
		
}

static void inti()
{
	std::cout << "     === PhoneBook ===" << std::endl;

	std::cout << "ADD : for adding a contact" << std::endl;
	std::cout << "SEARCH : for seatch a contact" << std::endl;
	std::cout << "EXIT : for exiting the phonebook" << std::endl;
}

static bool switch_case(PhoneBook& pb,Contact& contact, const std::string line)
{
	
	if (line == "ADD" || line == "add" || line == "Add")
	{
		pb.add(contact);
		pb.incrementCount();
	}
	else if (line == "SEARCH" || line == "search" || line == "Search")
		return true;
	else if (line == "EXIT" || line == "exit" || line == "Exit")
		return true;
	else
	{
		system("clear");
		std::cout << "Command not found please retry" << std::endl;
		std::cout << "" << std::endl;
		return false;
	}
	return true;
}