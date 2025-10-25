#include <iostream>

std::string toLower(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = std::tolower(str[i]);
    }
    return str;
}