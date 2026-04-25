#include "include/Span.hpp"



int main()
{
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;


    Span bigSpan(1000000);
    std::vector<int> data;

    for (int i = 0; i < 1000000; i++)
        data.push_back(rand());

    try
    {
        bigSpan.addRange(data.begin(), data.end());
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   

    std::cout << "Big shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Big longest: " << bigSpan.longestSpan() << std::endl;

    return 0;
}