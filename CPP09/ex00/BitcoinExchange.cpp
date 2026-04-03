#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFilename) {
    if (!loadDatabase(dbFilename)) {
        std::cerr << "Error: could not load database file." << std::endl;
        exit(1);
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::trim(std::string& s) const {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos)
        s = "";
    else
        s = s.substr(start, end - start + 1);
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) return false;

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            std::string rateStr = line.substr(commaPos + 1);
            trim(date);
            trim(rateStr);
            char* end;
            float rate = static_cast<float>(std::strtod(rateStr.c_str(), &end));
            _database[date] = rate;
        }
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeap ? 29 : 28)) return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    if (valueStr.empty()) return false;
    char* end;
    value = static_cast<float>(std::strtod(valueStr.c_str(), &end));
    if (end == valueStr.c_str() || (*end != '\0' && *end != 'f')) return false; 
    return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
    if (it != _database.end() && it->first == date) {
        return it->second;
    }
    if (it == _database.begin()) {
        return 0.0f; // Pas de date antérieure
    }
    --it;
    return it->second;
}

void BitcoinExchange::processInput(const std::string& inputFilename) const {
    std::ifstream file(inputFilename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header
    trim(line);
    if (line != "date | value") {
        // Maybe it's a data line or bad header, process it later or just throw an error
        file.clear();
        file.seekg(0, std::ios::beg); // Restart from beginning!
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);
        trim(date);
        trim(valueStr);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value)) {
             std::cerr << "Error: bad input => " << line << std::endl;
             continue;
        }

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = getExchangeRate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}
