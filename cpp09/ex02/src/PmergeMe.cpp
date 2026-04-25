#include "../include/PmergeMe.hpp"


void PmergeMe::printVector(const std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    if (argc < 2)
        throw std::runtime_error("Usage: ./PmergeMe <positive integers...>");

    for (int i = 1; i < argc; ++i) 
    {
        std::istringstream ss(argv[i]);
        long val;
        if (!(ss >> val) || !ss.eof())
            throw std::runtime_error("Error: invalid input '" + std::string(argv[i]) + "'");
        if (val <= 0)
            throw std::runtime_error("Error: not a positive integer '" + std::string(argv[i]) + "'");
        if (val > INT_MAX)
            throw std::runtime_error("Error: number too large '" + std::string(argv[i]) + "'");
    
        _input.push_back(static_cast<int>(val));
    }
}

unsigned int PmergeMe::fordJohnson(Container &seq)
{
    unsigned int comps = 0;
    int n = static_cast<int>(seq.size());
    if (n <= 1)
        return 0;
    

    return 0;
}

void PmergeMe::run()
{
    printVector(_input);
    std::vector<Counted> counted_input;

    unsigned int CounterComparisons = 0;

    ssize_t n = static_cast<ssize_t>(_input.size());

    for (ssize_t i = 0; i < n; ++i)
    {
        counted_input.push_back(Counted(_input[i], &CounterComparisons));
    }

    std::clock_t start = std::clock();
    unsigned int comparisons = fordJohnson(counted_input);
    std::clock_t end = std::clock();

}

PmergeMe::~PmergeMe()
{
}
