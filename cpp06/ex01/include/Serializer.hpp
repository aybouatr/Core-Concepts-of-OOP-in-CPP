#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> 
#include <iostream> 

struct Data 
{
    int id;
    std::string name;
};

class Serializer 
{
public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif