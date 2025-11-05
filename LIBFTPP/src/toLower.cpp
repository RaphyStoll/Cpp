#include <iostream>

/**
 * @brief Convertit tous les caractères d'une chaîne en minuscules
 *
 * @param str chaîne à convertir (copie)
 * @return std::string chaîne convertie
 */
std::string toLower(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = std::tolower(str[i]);
    }
    return str;
}