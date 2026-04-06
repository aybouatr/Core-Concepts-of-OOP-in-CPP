#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
    enum eDataType
    {
        Int,
        Char,
        Float,
        Double,
        InfinMoinsDouble,
        InfinPlusDouble,
        InfinMoinsFloat,
        InfinPlusFloat,
        NanDouble,
        NanFloat,
        NOTFOUND
    };
    
    static eDataType GetType(const std::string str);
    static void ConvertToChar(const std::string str, eDataType type);
    static void ConvertToInt(const std::string str, eDataType type);
    static void ConvertToFloat(const std::string str, eDataType type);
    static void ConvertToDouble(const std::string str, eDataType type);
    static bool checkIsInfinity(const std::string str);
    static eDataType GetSpecifiqueInfinity(const std::string str);
    static bool checkISChar(const std::string str);
    static bool checkIsInt(const std::string str);
    static bool checkIsFloat(const std::string str);
    static bool checkIsDouble(const std::string str);
    static bool printInfinityDouble(const std::string str);
    static bool printInfinityFloat(const std::string str);


public:

    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    static void Convert(std::string literal);
};


#endif



