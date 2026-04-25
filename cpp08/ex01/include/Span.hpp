#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <climits>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:

    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other); 
    ~Span();

    void addNumber(int number);

    int shortestSpan();
    int longestSpan();

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        if (_numbers.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Adding range exceeds capacity");

        _numbers.insert(_numbers.end(), begin, end);
    }
};






#endif