#include "../include/Bureaucrat.hpp"


Bureaucrat::Bureaucrat() :_name("Default") , _grade(150)
{
    
}

Bureaucrat::Bureaucrat(int grade,std::string name) : _name(name) , _grade(150)
{
    if (grade > 149)
        throw Bureaucrat::GradeTooLowException();
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}

void  Bureaucrat:: _checkRange(int n)
{
    if ((_grade + n) > 150)
        throw Bureaucrat::GradeTooLowException();
    if((_grade + n) < 1)
        throw Bureaucrat::GradeTooHighException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!"; 
}

void Bureaucrat::decreamentGrade()
{
    _checkRange(1);
    _grade++;
}

void Bureaucrat::increamentGrade()
{
    _checkRange(-1);
    _grade--;
}


std::ostream &operator<<(std::ostream &os,Bureaucrat  &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}

const std::string Bureaucrat::getName()
{
    return (_name);
}

int Bureaucrat::getGrade()
{
    return _grade;
}