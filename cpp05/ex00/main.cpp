
#include <exception>
#include "include/Bureaucrat.hpp"


class test
{
private:
    
    int age;

public:

    test(int age)
    {
        if (age > 55)
            throw heightAge();
        if (age < 10)
            throw LowAge();
        this->age = age;
    }

    int getAge()
    {
        return age;
    }

    class heightAge : public std::exception
    {
        virtual const char* what() const throw ()
        {
            return ("this is very height he should die ");
        }
    };

    class LowAge : public std::exception
    {
        virtual const char* what() const throw () 
        {
            return ("this is very law he should go shool ");
        }
    };

};





int main(void)
{
   

    std::cout << "\033[33m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;
    try
    {
        Bureaucrat Sleeper1(1500, "Bernd");   // grade first, name second
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Sleeper2(-10, "Olaf");    // grade first, name second
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\033[33m" << std::endl << "Test increasing" << "\033[0m" << std::endl;
    Bureaucrat bob(2, "Bob");
    std::cout << bob;

    try
    {
        bob.increamentGrade();   // your spelling
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << bob;
    
    try
    {
        bob.increamentGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << bob;



    std::cout << "\033[33m" << std::endl << "Test decreasing" << "\033[0m" << std::endl;
    Bureaucrat tim(149, "Tim");
    std::cout << tim;

    try
    {
        tim.decreamentGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << tim;
    
    try
    {
        tim.decreamentGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << tim;
    
    return (0);
}
