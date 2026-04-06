#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter
{
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
    eDataType GetType(const std::string str) const;
    void ConvertToChar(const std::string str, eDataType type) const;
    void ConvertToInt(const std::string str, eDataType type) const;
    void ConvertToFloat(const std::string str, eDataType type) const;
    void ConvertToDouble(const std::string str, eDataType type) const;

public:

    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    static void Convert(std::string literal);
    ScalarConverter::eDataType  ScalarConverter::GetType(const std::string str) const;
    ~ScalarConverter();
    

    static void Convert(std::string literal);

};


#endif



