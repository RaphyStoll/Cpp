#include <string>
#include <iostream>

std::string pad_line(const std::string& title) {
    std::string line;
    line += "+";
    line += std::string(38, '-');
    line += "+";
    std::string header = line + "\n";
    header += "| ";
    header += title;
    if (title.size() < 36) header += std::string(36 - title.size(), ' ');
    header += " |";
    header += "\n";
    header += line;
    return header;
}