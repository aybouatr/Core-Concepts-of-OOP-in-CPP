/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:28:24 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/15 09:28:28 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/PhoneBook.hpp"


int main()
{
    PhoneBook 	PhoneBook;
	bool		run = true;
	std::string	command;

	PhoneBook.ShowInstruction();
	

    while (run && std::getline(std::cin , command))
	{
		if (command.compare("ADD") == 0 && PhoneBook._flag_error != true)
			PhoneBook.set_information();
		else if (command.compare("SEARCH") == 0 && PhoneBook._flag_error != true)
			PhoneBook.get_information();
		else if (command.compare("EXIT") == 0 && PhoneBook._flag_error != true)
		{
			std::cout << "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
			run = false;
			continue ;
		}
		if(PhoneBook._flag_error)
			return (1);
		command.clear();
		 PhoneBook.ShowInstruction ();
		std::cout << "\033[33m$>\033[0m";
	}
	if (run)
	{
		std::cout << "You pressed ^D, exiting now." << command << std::endl
		<< "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
	}
	return (0);
}


