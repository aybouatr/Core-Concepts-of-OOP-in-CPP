#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string t)
    : AForm("Pardon", 25, 5), target(t) {}

void PresidentialPardonForm::action() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n"; 
} 

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}


void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeExecute())
        throw AForm::GradeTooLowException();
    action();
}