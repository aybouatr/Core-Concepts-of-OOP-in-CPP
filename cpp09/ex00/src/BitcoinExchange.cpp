#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *inputFile)
    : inputFile(inputFile)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::ParsingDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    try
    {
        std::istringstream yearStream(date.substr(0, 4));
        std::istringstream monthStream(date.substr(5, 2));
        std::istringstream dayStream(date.substr(8, 2));
        int year;
        int month;
        int day;

        if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }

        if (month < 1 || month > 12 || day < 1)
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (IsLeapYear(year))
            daysInMonth[2] = 29;

        if (day > daysInMonth[month])
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }
    }
    catch (const std::exception &)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    return true;
}

void BitcoinExchange::LoadDataFromBase()
{
    std::ifstream dataFile("./DataBase/data.csv");
    if (!dataFile.is_open())
        throw std::runtime_error("Error opening data file.");

    std::string line;
    std::getline(dataFile, line);

    while (std::getline(dataFile, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
            continue;

        try
        {
            std::istringstream valueStream(valueStr);
            double value;

            if (!(valueStream >> value))
                continue;
            dBase[date] = value;
        }
        catch (const std::exception &)
        {
        }
    }
}

void BitcoinExchange::SearcheRateinBaseAndDisplay(const std::string &date, double value)
{
    std::map<std::string, double>::const_iterator it = dBase.lower_bound(date);

    if (it == dBase.end())
    {
        if (dBase.empty())
            return;
        --it;
    }
    else if (it->first != date && it != dBase.begin())
    {
        --it;
    }

    std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
}

void BitcoinExchange::DeleteLeadingTrailingSpaces(std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos || end == std::string::npos)
    {
        str.clear();
        return;
    }

    str = str.substr(start, end - start + 1);
}

void BitcoinExchange::ReadDataFromFileAndCalculate()
{
    file.open(inputFile);
    if (!file.is_open())
        throw std::runtime_error(std::string("Error opening file: ") + inputFile);

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        DeleteLeadingTrailingSpaces(date);
        DeleteLeadingTrailingSpaces(valueStr);
        
        std::istringstream valueStream(valueStr);
        double value;

        if (!(valueStream >> value))
        {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        if (!ParsingDate(date))
            continue;

        SearcheRateinBaseAndDisplay(date, value);
    }
}

void BitcoinExchange::Execute()
{
    LoadDataFromBase();
    ReadDataFromFileAndCalculate();
}