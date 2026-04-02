#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _sign;
    const int _gradeSign;
    const int _gradeExecute; 

public:
    Form();
    Form(const std::string name,const int gradeSign, const int gradeExecute);
    Form(const Form& form);
    Form &operator=(const Form& form);
    ~Form();

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
};

std::ostream &operator<<(std::ostream &o, const Form &f);
