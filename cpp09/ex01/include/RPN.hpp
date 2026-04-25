#pragma once 

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class RPN
{
private:

    std::string inputFile;
    std::stack<int> operands;
    void CalculatedResult();
    void ParsingExpression();

public:

    RPN(char *inputFile);
    ~RPN();
    void Execute();
};
