#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Intern.hpp"
#include "include/AForm.hpp"

#include <iostream>

int main(void)
{
	// shrubbery  robotomy  presidential ====> type write correct way 
	{
		try
		{
			Intern it;

			AForm *frm1 = it.makeForm("presidential", "ayoub");

			std::cout << "Name : " << frm1->getName() << std::endl;

			Bureaucrat b1("slave1", 1);

			b1.signForm(*frm1);
			b1.executeForm(*frm1);

			delete frm1;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n\n";

	{
		try
		{
			Intern it;
			AForm *frm = it.makeForm("robotomy", "Voss");


			Bureaucrat b("slave2", 5);

			b.signForm(*frm);
			frm->execute(b);

			delete frm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

	}

	return 0;
}