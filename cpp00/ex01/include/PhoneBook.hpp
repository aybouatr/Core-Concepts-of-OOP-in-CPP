/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:30:56 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/15 09:31:00 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <limits>
#include "Contact.hpp"
# define MAX_CONTACTS 8

class PhoneBook 
{
	private:
		int 	_num_entries;
		bool	_full;
		std::string GetCorrrectInputString(const std::string& Message);
		void 	printTable() const;

	public:
		bool 	_flag_error;
		Contact contacts[MAX_CONTACTS];
		PhoneBook();
		~PhoneBook();
		void 	ShowInstruction();
		void	set_information();
		void	get_information();
		int 	getNumEntries();

};


# endif
