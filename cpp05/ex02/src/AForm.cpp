#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"




Form::Form():_name("D_form"),_sign(false),_gradeSign(70),_gradeExecute(10)
{

}

Form::Form(const std::string name,const int gradeSign,const int gradeExecute) : 
    _name(name),_sign(false),_gradeSign(gradeSign),_gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();

}

Form &Form::operator=(const Form& form)
{
    if (this != &form)
        _sign = form._sign;
    return (*this);
}


Form::Form(const Form& form) :
    _name(form._name),_sign(form._sign),_gradeSign(form._gradeSign),_gradeExecute(form._gradeExecute)
{

}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

Form::~Form()
{

}
const std::string &Form::getName() const 
{ 
    return _name;
}

bool Form::isSigned() const 
{ 
    return _sign;
}

int Form::getGradeSign() const 
{ 
    return _gradeSign;
}

int Form::getGradeExecute() const 
{ 
    return _gradeExecute;
}

void Form::beSigned(const Bureaucrat& salve)
{
    if (salve.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _sign = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form \"" << form.getName() << "\", "
       << "Sign grade: " << form.getGradeSign() << ", "
       << "Execute grade: " << form.getGradeExecute() << ", "
       << "Signed: " << (form.isSigned() ? " Yes " : " No ");

    return os;
}