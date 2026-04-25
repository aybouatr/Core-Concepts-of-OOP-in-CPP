#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>

#define INT_MAX 2147483647

struct Counted 
{
    int          value;
    std::string  marked;
    unsigned int *counter;

    Counted(int v, unsigned int *c) : value(v), counter(c) 
    {

    }

    bool operator<(const Counted &rhs) const 
    {
        if (counter) 
            ++(*counter);
        return value < rhs.value;
    }
   
}

class PmergeMe
{
private:
    std::vector<int> _input;

    std::string GetMarked(int Value);

public:

    PmergeMe(int argc, char **argv);
    void printVector(const std::vector<int> &vec);
    void run();
    ~PmergeMe();
};


std::string PmergeMe::GetMarked(int Value)
{
    static unsigned int Winner;
    static unsigned int loser;

    if (Value == 1)
    {
        std::string marked = "a" + std::to_string(Winner)
        Winner++;
       return marked;
    }
    else if (Value == 0)
    {
        std::string marked = "b" + std::to_string(loser);
        loser++;
        return marked;
    }
    return "";
}












#endif


