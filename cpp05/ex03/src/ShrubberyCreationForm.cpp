
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t)
    : AForm("Shrubbery", 145, 137), target(t) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}



void ShrubberyCreationForm::action() const
{
    std::ofstream file((target + "_shrubbery").c_str());

    file << "   /\\\n";
    file << "  /**\\\n";
    file << " /****\\\n";
    file << "/******\\\n";
    file << "  ||\n";
    file << "\n\n";
    file << "   /\\\n";
    file << "  /**\\\n";
    file << " /****\\\n";
    file << "/******\\\n";
    file << "  ||\n";

    file.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeExecute())
        throw AForm::GradeTooLowException();
    action();

}