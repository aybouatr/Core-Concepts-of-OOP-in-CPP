#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"


class Intern
{
    enum FormType 
    {
        SHRUBBERY,
        ROBOTOMY,
        PRESIDENTIAL,
        UNKNOWN
    };
    FormType getFormType(const std::string& name);

public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();
    AForm *makeForm(std::string formName, std::string target); 
};

#endif