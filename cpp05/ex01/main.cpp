#include <exception>
#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main(void)
{
    std::cout << "\033[33m\nTest ex01\033[0m" << std::endl;

    std::cout << "\033[33m\nTest too high and too low creation\033[0m" << std::endl;

    try 
    {
        Bureaucrat Sleeper1("Bernd", 1500);
    }
    catch (const std::exception &e) 
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat Sleeper2("Olaf", -10);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\033[33m\nTest increasing\033[0m" << std::endl;

    Bureaucrat bob("Bob", 2);
    std::cout << bob;

    try
    {
        bob.increamentGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << bob;

    try
    {
        bob.increamentGrade();
    }
    catch (const std::exception &e) 
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << bob;

    std::cout << "\033[33m\nTest decreasing\033[0m" << std::endl;

    Bureaucrat tim("Tim", 149);
    std::cout << tim;

    try 
    {
        tim.decreamentGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << tim;

    try 
    {
        tim.decreamentGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << tim;


    std::cout << "\033[33m\nTest ex01 (Form signing)\033[0m" << std::endl;

    Form id_form("ID FORM", 100, 90);
    Bureaucrat mr_slow("SlowGuy", 150);
    Bureaucrat mr_id("MR_ID", 100);

    std::cout << id_form;

    try
    {
        mr_slow.signForm(id_form);  // too low → will fail
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << id_form;

    try
    {
        mr_id.signForm(id_form);   // OK
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << id_form;

    return 0;

}
