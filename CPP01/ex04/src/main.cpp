#include <iostream>
#include <fstream>

static std::string replaceAll(std::string line, std::string s1, std::string s2);

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Usage : ./replace Filename s1 s2" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	std::ifstream infile(filename);
	if (!infile.is_open()) {
		std::cout << "Error: Open " << filename << " failed" << std::endl;
		return 1;
	}

	std::ofstream outfile(filename + ".replace");
	if (!outfile.is_open()) {
		std::cout << "Error: Open " << filename << ".replace failed" << std::endl;
		infile.close();
		return 1;
	}

	std::string line;
	while(std::getline(infile, line)) {
		std::string replaced = replaceAll(line, s1, s2);
		outfile << replaced << std::endl;
	}

	infile.close();
	outfile.close();

	return 0;
}

static std::string replaceAll(std::string str, std::string s1, std::string s2)
{
	if (s1.empty()) {
		return str;
	}

	size_t pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos) {
		str = str.substr(0, pos) + s2 + str.substr(pos + s1.length());
		pos += s2.length();
	}
	return str;
}