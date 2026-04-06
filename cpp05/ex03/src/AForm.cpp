#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm():_name("D_form"),_sign(false),_gradeSign(70),_gradeExecute(10)
{

}

AForm::AForm(const std::string name,const int gradeSign,const int gradeExecute) : 
    _name(name),_sign(false),_gradeSign(gradeSign),_gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();

}

AForm &AForm::operator=(const AForm& form)
{
    if (this != &form)
        _sign = form._sign;
    return (*this);
}


AForm::AForm(const AForm& Aform) :
    _name(Aform._name),_sign(Aform._sign),_gradeSign(Aform._gradeSign),_gradeExecute(Aform._gradeExecute)
{

}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Not Sign this Form! ";
}



AForm::~AForm()
{

}
const std::string &AForm::getName() const 
{ 
    return _name;
}

bool AForm::isSigned() const 
{ 
    return _sign;
}

int AForm::getGradeSign() const 
{ 
    return _gradeSign;
}

int AForm::getGradeExecute() const 
{ 
    return _gradeExecute;
}

void AForm::beSigned(const Bureaucrat& salve)
{
    if (salve.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _sign = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form \"" << form.getName() << "\", "
       << "Sign grade: " << form.getGradeSign() << ", "
       << "Execute grade: " << form.getGradeExecute() << ", "
       << "Signed: " << (form.isSigned() ? " Yes " : " No ");

    return os;
}