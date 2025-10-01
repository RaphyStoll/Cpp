#include "contact.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <cctype>
#include <sstream>
#include <cstdlib>

static std::string formatField(const std::string &s);
static std::string intToString(int n);

int PhoneBook::search() const {
	if (this->count == 1) {
		std::cout << "PhoneBook empty." << std::endl;
		return 0;
	}

	int start = (this->count == 8) ? this->next : 0;

	std::cout << formatField("INDEX") << '|' \
			  << formatField("FIRST NAME") << '|' \
			  << formatField("LAST NAME") << '|' \
			  << formatField("NICKNAME") << std::endl;

	for (int logical = 0; logical < this->count; ++logical) {
		int phys = (start + logical) % 8; // calcu de l'index phisuqe dans le tab
		const Contact &c = this->contact[phys];
		std::cout << formatField(intToString(logical)) << '|' \
				  << formatField(c.getFirstName()) << '|' \
				  << formatField(c.getLastName()) << '|' \
				  << formatField(c.getNickName()) << std::endl;
	}

	std::string line;
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, line)) {
		std::cout << "Input aborted." << std::endl;
		return 0;
	}
	if (line.empty()) { std::cout << "Empty input." << std::endl; return 0; }
	for (size_t k = 0; k < line.length(); ++k) {
		if (!std::isdigit(static_cast<unsigned char>(line[k]))) { std::cout << "Invalid format." << std::endl; return 0; }
	}
	int logicalIdx = std::atoi(line.c_str());
	if (logicalIdx < 0 || logicalIdx >= this->count) { std::cout << "Index out of range." << std::endl; return 0; }
	int physIdx = (start + logicalIdx) % 8;

	const Contact &c = this->contact[physIdx];
	std::cout << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << "Logical index: " << logicalIdx << " (physical slot: " << physIdx << ")" << std::endl;
	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nick name: " << c.getNickName() << std::endl;
	std::cout << "Pnone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << c.getDarkestSecret() << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << std::endl;
	return 1;
}

// formate un champ sur 10 caractères (tronque et ajoute '.')
static std::string formatField(const std::string &s) {
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	if (s.length() == 10)
		return s;
	return std::string(10 - s.length(), ' ') + s;
}

static std::string intToString(int n) {
	std::ostringstream oss; oss << n; return oss.str();
}