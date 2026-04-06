#include "../include/ScalarConverter.hpp"

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

ScalarConverter::eDataType ScalarConverter::GetSpecifiqueInfinity(const std::string str) const
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
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; str[i]; i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::checkIsFloat(const std::string str)
{
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
    return (str.back() == 'f');
}

bool ScalarConverter::checkIsDouble(const std::string str)
{
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

ScalarConverter::eDataType  ScalarConverter::GetType(const std::string str) const
{
    int len = str.length();

      if (len == 0)
        return NOTFOUND;

    if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff" || str == "nan" || str == "nanf")
        return ;
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

void ScalarConverter::ConvertToChar(const std::string str, eDataType type) const
{
   
    if (type == NOTFOUND ||  type == InfinMoinsDouble || type == InfinPlusDouble || type == InfinMoinsFloat || type == InfinPlusFloat || type == NanDouble || type == NanFloat)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    if (type == Char)
    {         
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else
    {
        int i = std::stoi(str);
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

void ScalarConverter::ConvertToInt(const std::string str, eDataType type) const
{
    // Implementation of conversion to int based on the type
}

void ScalarConverter::ConvertToFloat(const std::string str, eDataType type) const
{
    // Implementation of conversion to float based on the type
}

void ScalarConverter::ConvertToDouble(const std::string str, eDataType type) const
{
    // Implementation of conversion to double based on the type
}



void ScalarConverter::Convert(std::string literal)
{
    eDataType Type =  GetType(literal);
    ConvertToChar(literal, Type);
    ConvertToInt(literal, Type);
    ConvertToFloat(literal, Type);
    ConvertToDouble(literal, Type);
}