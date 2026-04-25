#include "../include/RPN.hpp"


RPN::RPN(char *inputFile)
{
    this->inputFile = std::string(inputFile);
}

void RPN::ParsingExpression()
{
    std::istringstream iss(inputFile);
    std::string token;

    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (operands.size() < 2)
                throw std::runtime_error("Error: not enough Numbers for operator " + token);

            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();

            if (token == "+")
                operands.push(a + b);
            else if (token == "-")
                operands.push(a - b);
            else if (token == "*")
                operands.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero");
                operands.push(a / b);
            }
        }
        else
        {
            if (token.length() != 1 || !isdigit(token[0]))
            {
                throw std::runtime_error("Error:");
            }
            std::istringstream numStream(token);
            int num;
            if (!(numStream >> num))
                throw std::runtime_error("Error: invalid number " + token);
            operands.push(num);
        }
    }
}

void RPN::CalculatedResult()
{
    if (operands.size() != 1)
        throw std::runtime_error("Error: invalid RPN expression");

    std::cout << operands.top() << std::endl;
}

void RPN::Execute()
{

    try
    {
        ParsingExpression();
        CalculatedResult();
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}

RPN::~RPN()
{
    while (!operands.empty())
        operands.pop();
}