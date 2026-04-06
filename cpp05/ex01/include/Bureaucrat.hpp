#pragma once 

#include <iostream>
#include "Form.hpp"


class Bureaucrat
{

private:

    const std::string _name; 
    int _grade;

public:

    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat( std::string name,int grade);
    const std::string getName();
    int getGrade() const;
    void increamentGrade();
    void decreamentGrade();
    void signForm(Form &f);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw ();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw ();
    };


};

std::ostream &operator<<(std::ostream &os,Bureaucrat  &other);
