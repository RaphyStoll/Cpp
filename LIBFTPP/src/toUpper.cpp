#include <iostream>

/**
 * @brief Convertit tous les caractères d'une chaîne en majuscules
 *
 * @param str chaîne à convertir (copie)
 * @return std::string chaîne convertie
 */
std::string toUpper(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = std::toupper(str[i]);
    }
    return str;
}