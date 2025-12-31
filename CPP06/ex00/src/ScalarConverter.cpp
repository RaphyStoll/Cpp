#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string &literal)
{
	return (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
			literal == "-inf" || literal == "+inf" || literal == "nan");
}

static void printPseudoLiteral(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(std::string const & literal)
{
	if (isPseudoLiteral(literal))
	{
		printPseudoLiteral(literal);
		return;
	}

	// Détection d'un littéral char
	// Un littéral char est un caractère unique qui n'est PAS un chiffre
	if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return;
	}

	// Essai de parsing en double
	char *endptr;
	errno = 0;
	double d = std::strtod(literal.c_str(), &endptr);

	// Vérification de la réussite de la conversion
	// Réussie si endptr pointe vers la fin ou vers 'f' à la fin (float)
	bool isFloatLiteral = (*endptr == 'f' && *(endptr + 1) == '\0');
	bool isDoubleLiteral = (*endptr == '\0');

	if (!isFloatLiteral && !isDoubleLiteral)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// Conversion en Char
	// Vérifie si la valeur tient dans un char et est affichable
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || std::isnan(d))
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (std::isprint(static_cast<char>(d)))
	{
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}

	// Conversion en Int
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

	// Conversion en Float
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;

	// Conversion en Double
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
