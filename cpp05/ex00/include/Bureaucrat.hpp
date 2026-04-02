#pragma once 

#include <iostream>



class Bureaucrat
{

private:

    const std::string _name;
    int _grade;
    void _checkRange(int n);

public:

    Bureaucrat();
    Bureaucrat(int grade,std::string name);
    const std::string getName();
    int getGrade() ;
    void increamentGrade();
    void decreamentGrade();

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
