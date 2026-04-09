#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <exception>
#include <time.h>
#include "../src/Array.cpp"



template <typename T>

class Array
{
private:
    T *arr;
    unsigned int size;
    
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    ~Array();
};




#endif