#include "../include/ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <climits>
#include <limits>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this; 
}


bool ScalarConverter::checkIsInfinity(const std::string str)
{
    int len = str.length();
    if ((str == "+inf" || str == "-inf" ||  str == "nanf") && len == 4)
        return true;

    if (( str == "+inff" || str == "-inff") && len == 5)
        return true;

    if (( str == "nan" ) && len == 3)
        return true;

    return false;
}

ScalarConverter::eDataType ScalarConverter::GetSpecifiqueInfinity(const std::string str)
{
    if (str == "+inf")
        return InfinPlusDouble;
    if (str == "-inf")
        return InfinMoinsDouble;
    if (str == "+inff")
        return InfinPlusFloat;
    if (str == "-inff")
        return InfinMoinsFloat;
    if (str == "nan")
        return NanDouble;
    if (str == "nanf")
        return NanFloat;
    return NOTFOUND;
}

bool ScalarConverter::checkISChar(const std::string str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}

bool ScalarConverter::checkIsInt(const std::string str)
{
    if (str.empty())
        return false;
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (i == static_cast<int>(str.length()))
        return false;
    for (; str[i]; i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::checkIsFloat(const std::string str)
{
    if (str.empty())
        return false;
    int i = 0;
    bool dotFound = false;

    if (str[i] == '-' || str[i] == '+')
        i++;

    for (; str[i]; i++)
    {
        if (str[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(str[i]) && str[i] != 'f')
            return false;

    }
    return (str[str.length() - 1] == 'f');
}

bool ScalarConverter::checkIsDouble(const std::string str)
{
    if (str.empty())
        return false;
    int i = 0;
    bool dotFound = false;

    if (str[i] == '-' || str[i] == '+')
        i++;

    for (; str[i]; i++)
    {
        if (str[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(str[i]))
            return false;

    }
    return true;
}

ScalarConverter::eDataType  ScalarConverter::GetType(const std::string str)
{
    int len = str.length();

      if (len == 0)
        return NOTFOUND;

    if (checkIsInfinity(str))
        return GetSpecifiqueInfinity(str);
    if (checkISChar(str))
        return Char;
    if (checkIsInt(str))
        return Int;
    if (checkIsFloat(str))
        return Float;
    if (checkIsDouble(str))
        return Double;
    return NOTFOUND;

}

void ScalarConverter::ConvertToChar(const std::string str, eDataType type)
{
   
    if (type == NOTFOUND ||  type == InfinMoinsDouble || type == InfinPlusDouble || type == InfinMoinsFloat || type == InfinPlusFloat || type == NanDouble || type == NanFloat)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    if (type == Char)
    {         
        char c = str[0];
        std::cout << "char:'" << c << "'" << std::endl;
    }
    else
    {
        int i = std::atoi(str.c_str());
        if (i < 0 || i > 127)
        {
            std::cout << "char: impossible" << std::endl;
            return;
        }
        char c = static_cast<char>(i);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

}

void ScalarConverter::ConvertToInt(const std::string str, eDataType type)
{
   if (type == NOTFOUND ||  type == InfinMoinsDouble || type == InfinPlusDouble || type == InfinMoinsFloat || type == InfinPlusFloat || type == NanDouble || type == NanFloat)
    {
        std::cout << "int : impossible" << std::endl;
        return;
    }

    if (type == Int)
    {
        std::cout << "int: " << str << std::endl;
        return;
    }
    else if (type == Char)
    {
        char c = str[0];
        std::cout << "int: " << static_cast<int>(c) << std::endl;
    }
    else
    {
        double d = std::atof(str.c_str());
        if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
        {
            std::cout << "int: impossible" << std::endl;
            return;
        }
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }



}

bool ScalarConverter::printInfinityFloat(const std::string str)
{
    if (str == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        return true;
    }
    if (str == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        return true;
    }
    if (str == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::ConvertToFloat(const std::string str, eDataType type)
{
    if (type == NOTFOUND ||  type == InfinMoinsDouble || type == InfinPlusDouble || type == NanDouble)
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
     if (type == InfinMoinsFloat)
    {
        return;
    }
    if (type == Float)
    {
        std::cout << "float: " << str << std::endl;
        return;
    }
    else if (type == Char)
    {
        char c = str[0];
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    }
    else
    {
        double d = std::atof(str.c_str());
        if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        {
            std::cout << "float: impossible" << std::endl;
            return;
        }
        std::cout << "float: " << static_cast<float>(d) << ".f" << std::endl;
    }
}

bool ScalarConverter::printInfinityDouble(const std::string str)
{
    if (str == "+inff")
    {
        std::cout << "double: +inf" << std::endl;
        return true;
    }
    if (str == "-inf" )
    {
        std::cout << "double: -inf" << std::endl;
        return true;
    }
    if (str == "nan")
    {
        std::cout << "double: nan" << std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::ConvertToDouble(const std::string str, eDataType type)
{

    if (type == NOTFOUND ||  type == InfinMoinsFloat || type == InfinPlusFloat || type == NanFloat)
    {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (printInfinityDouble(str))
        return;
    if (type == Double)
    {
        std::cout << "double: " << str << std::endl;
        return;
    }
    else if (type == Char)
    {
        char c = str[0];
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
    else
    {
        double d = std::atof(str.c_str());
        std::cout << "double: " << d << std::endl;
    }
}


void ScalarConverter::Convert(std::string literal)
{
    eDataType Type =  GetType(literal);
    ConvertToChar(literal, Type);
    ConvertToInt(literal, Type);
    ConvertToFloat(literal, Type);
    ConvertToDouble(literal, Type);
}