
#include <exception>
#include "include/Bureaucrat.hpp"



int main(void)
{
   

    std::cout << "\033[33m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;

    try
    {
        Bureaucrat Sleeper1(151, "Bernd");
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Sleeper2(0, "Olaf"); 
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\033[33m" << std::endl << "Test increasing" << "\033[0m" << std::endl;

    Bureaucrat bob(2, "Bob");
    
    std::cout << bob;
    try
    {
        bob.increamentGrade();  
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    std::cout << bob;
    
    try
    {
        bob.increamentGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    std::cout << bob;



    std::cout << "\033[33m" << std::endl << "Test decreasing" << "\033[0m" << std::endl;
    Bureaucrat tim(150, "Tim");

    std::cout << tim;

    try
    {
        tim.decreamentGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    std::cout << tim;
    
    try
    {
        tim.decreamentGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << tim;
    return (0);

}
