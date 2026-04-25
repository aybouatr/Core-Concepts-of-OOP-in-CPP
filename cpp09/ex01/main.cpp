#include "../include/RPN.hpp"


int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    try
    {
        RPN rpn(argv[1]);
        rpn.Execute();
       
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
   
}