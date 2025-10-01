#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "phonebook.hpp"
#include "config.hpp"
#include "debug.hpp"

static void inti();
static bool switch_case(PhoneBook& pb, const std::string line);

int main ()
{
	
	std::string line;
	PhoneBook pb = PhoneBook();

	system("clear");	

	while (1)
	{
		inti();
		std::getline(std::cin, line);
		if (switch_case(pb, line))
			continue ;
		else
			break ;
	}
	return 0;
}

static void inti()
{
	std::cout << "     === PhoneBook ===" << std::endl;

	std::cout << "ADD : for adding a contact" << std::endl;
	std::cout << "SEARCH : for seatch a contact" << std::endl;
	std::cout << "EXIT : for exiting the phonebook" << std::endl;
}

static bool switch_case(PhoneBook& pb, const std::string line)
{
	system("clear");
	if (line == "ADD" || line == "add" || line == "Add")
	{
		pb.add();
		return true;
	}
	else if (line == "SEARCH" || line == "search" || line == "Search")
	{
		
		pb.search();
		return true;
	}
	else if (line == "EXIT" || line == "exit" || line == "Exit")
		return false;
	else
	{
		system("clear");
		std::cout << "Command not found please retry" << std::endl;
		std::cout << "" << std::endl;
		return true;
	}
	return true;
}
