#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);

        ShrubberyCreationForm s("home");
        RobotomyRequestForm r("Bender");
        PresidentialPardonForm p("Alice");

        boss.signForm(s);
        boss.executeForm(s);

        boss.signForm(r);
        boss.executeForm(r);

        boss.signForm(p);
        boss.executeForm(p);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    

    return 0;
}