#include <iostream>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	void complain(std::string level);
};

void Harl::debug(void) { std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl; }

void Harl::info(void) { std::cout << " think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl; }

void Harl::warning(void) { std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl; }

void Harl::error(void) { std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; }

void Harl::complain(std::string level) {
	
	//tab de lvl qui contient toutes les options
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	//tap de pointeur sur fonction
// void (Harl::*functions[4])(void)
//   ^ type retour
//         ^ classe
//                 ^ nom du pointeur
//                             ^ paramètres
	void (Harl::*functions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return;
		}
	}

	std::cout << "Unknow level: " << level << std::endl;
}