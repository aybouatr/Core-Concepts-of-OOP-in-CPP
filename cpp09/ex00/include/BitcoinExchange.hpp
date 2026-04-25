#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange
{
private:
    char *inputFile;
    std::map<std::string, double> dBase;
    std::ifstream file;

    void LoadDataFromBase();
    void ReadDataFromFileAndCalculate();
    bool ParsingDate(const std::string &date);
    bool IsLeapYear(int year);
    void SearcheRateinBaseAndDisplay(const std::string &date, double value);
    void DeleteLeadingTrailingSpaces(std::string &str);

public:
    BitcoinExchange(char *inputFile);
    ~BitcoinExchange();

    void Execute();
};