/**
 * @file libftpp.hpp
 * @brief Petit utilitaire de manipulation de chaînes (fichier d'en-tête)
 *
 * Contient les déclarations des fonctions utilitaires fournies par la
 * bibliothèque libftpp : conversion en majuscules et en minuscules.
 */

#pragma once

#include "debug.hpp"
#include <string>

/**
 * @brief Convertit une chaîne en majuscules
 *
 * @param str chaîne à convertir (copie)
 * @return std::string chaîne convertie en majuscules
 */
std::string toUpper(std::string str);

/**
 * @brief Convertit une chaîne en minuscules
 *
 * @param str chaîne à convertir (copie)
 * @return std::string chaîne convertie en minuscules
 */
std::string toLower(std::string str);

//helper pour titre de test
std::string pad_line(const std::string& title);
