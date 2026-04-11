#include "../include/Span.hpp"


Span::Span(unsigned int N) : _maxSize(N)
{
    _numbers.reserve(N);
}

Span::Span(const Span& other)
    : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
    
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");

    _numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough elements");

    std::vector<int> temp = _numbers;
    std::sort(temp.begin(), temp.end());

    int minSpan = temp[1] - temp[0];

    for (size_t i = 1; i < temp.size() - 1; i++)
    {
        int span = temp[i + 1] - temp[i];
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough elements");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}

