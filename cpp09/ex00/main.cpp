#include "BitcoinExchange.hpp"




int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange bitcoinExchange(argv[1]);
        bitcoinExchange.Execute();
       
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
   
}
