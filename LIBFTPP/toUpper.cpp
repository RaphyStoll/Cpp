#include <iostream>

std::string toUpper(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = std::toupper(str[i]);
    }
    return str;
}