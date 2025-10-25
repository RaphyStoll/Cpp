#include <iostream>
#include "harl.hpp"
#include "libftpp.hpp"

//undef la macro de libftpp
#ifdef DEBUG
#undef DEBUG
#endif

enum Level {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3,
    UNKNOWN = -1
};

static Level getLevel(std::string str);

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	Harl harl;
	std::string mode = toUpper(argv[1]);
	Level level = getLevel(mode);

	switch (level)
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;

		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;

		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;

		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return 0;
}

static Level getLevel(std::string str) {
    if (str == "DEBUG") return DEBUG;
    if (str == "INFO") return INFO;
    if (str == "WARNING") return WARNING;
    if (str == "ERROR") return ERROR;
    return UNKNOWN;
}

