#include "debug.hpp"
#include "config.hpp"
#include <iostream>
#include <fstream>
#include <string>

void print_debug(const std::string str)
{
	#ifdef DEBUG
		static bool first = true;

		std::ios_base::openmode mode = std::ios::app; //mod append
		if (first) {
			mode = std::ios::trunc; //mode trunc
			first = false;
		}
		std::ofstream outfile("debug.log", mode);
		if (!outfile)
			return ;
		std::streambuf* oldbuf = std::cout.rdbuf();
		std::cout.rdbuf(outfile.rdbuf());
		std::cout << str << std::endl;
		std::cout.rdbuf(oldbuf);
	#else
		(void)str;
	#endif
}