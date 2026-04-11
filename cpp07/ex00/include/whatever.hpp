#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>


namespace whatever
{
    template <typename T>
    void swap(T &a, T &b) 
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

    template <typename T>
    T min(T const &a, T const &b)
    {
        return (b < a ? b : a);
    }

    template <typename T>
    T max(T const &a, T const &b)
    {
        return (b > a ? b : a);
    }

}


#endif