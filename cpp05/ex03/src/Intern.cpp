#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"


Intern::Intern()
{
}   

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}



Intern::FormType Intern::getFormType(const std::string& name) 
{
   return (name == "shrubbery") ? SHRUBBERY :
           (name == "robotomy") ? ROBOTOMY :
           (name == "presidential") ? PRESIDENTIAL :
           UNKNOWN;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    switch (getFormType(formName))
    {
        case SHRUBBERY:
        {
            std::cout << "Intern creates " << formName << std::endl;
            return new ShrubberyCreationForm(target);
        }
        case ROBOTOMY:
        {   
            std::cout << "Intern creates " << formName << std::endl;
            return new RobotomyRequestForm(target);
        }
        case PRESIDENTIAL:
        {
            std::cout << "Intern creates " << formName << std::endl;
            return new PresidentialPardonForm(target);
        }
        default:
            throw std::invalid_argument("Unknown form name: " + formName);
    }
}


Intern::~Intern() 
{

}