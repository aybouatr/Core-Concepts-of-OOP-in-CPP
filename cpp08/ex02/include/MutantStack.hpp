#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string.h>
#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:

    MutantStack()
    {

    }
    ~MutantStack()
    {

    }

    typedef typename std::deque<T>::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

    
    void push(T const & value)
    {
        this->c.push_back(value);
    }

    void pop()
    {
        this->c.pop_back();
    }

    T & top()
    {
        return this->c.back();
    }
};


#endif