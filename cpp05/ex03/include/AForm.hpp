#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
private:

    const std::string _name;
    bool _sign;
    const int _gradeSign;
    const int _gradeExecute; 

public:

    AForm();
    AForm(const std::string name,const int gradeSign, const int gradeExecute);
    AForm(const AForm& Aform);
    AForm &operator=(const AForm& form);
    virtual ~AForm();

    const std::string &getName() const; 
    bool isSigned() const;  
    int getGradeSign() const;  
    int getGradeExecute() const;

    void beSigned(const Bureaucrat& salve);
    
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    virtual void execute(const Bureaucrat &executor) const = 0;

};

std::ostream &operator<<(std::ostream &o, const AForm &f);
