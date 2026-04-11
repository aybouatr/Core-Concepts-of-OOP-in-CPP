#include "../include/Array.hpp"


template <typename T>
Array<T>::Array()
{
    size = 0;
    arr = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    size = n;
    arr = new T[size];
}

template <typename T>
Array<T>::Array(const Array &other)
{
    size = other.size;
    arr = new T[size];
    for (unsigned int i = 0; i < size; i++)
        arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] arr;
        size = other.size;
        arr = new T[size];
        for (unsigned int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return arr[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return arr[index];
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}



