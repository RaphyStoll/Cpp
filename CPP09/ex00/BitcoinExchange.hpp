#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    BitcoinExchange();
    bool loadDatabase(const std::string& filename);
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, float& value) const;
    float getExchangeRate(const std::string& date) const;
    void trim(std::string& s) const;

public:
    BitcoinExchange(const std::string& dbFilename);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void processInput(const std::string& inputFilename) const;
};

#endif
