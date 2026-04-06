#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string t)
    : AForm("Robotomy", 72, 45), target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::action() const
{
    std::cout << "Drilling noises...\n";

    if (rand() % 2)
        std::cout << target << " has been robotomized successfully\n";
    else
        std::cout << "Robotomy failed\n";
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeExecute())
        throw AForm::GradeTooLowException();
    action();

}