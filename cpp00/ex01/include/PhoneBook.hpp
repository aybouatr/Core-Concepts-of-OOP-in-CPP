#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

#include "Contact.hpp"



# define MAX_CONTACTS 8

class PhoneBook 
{
	private:
		int 	_num_entries;
		bool	_full;
		std::string get_corrrect_input_string(const std::string& Message);
		
		
		public:
		Contact contacts[MAX_CONTACTS];
		PhoneBook();
		~PhoneBook();
		void 	ShowInstruction();
		void	set_information();
		void	get_information() const;
		int 	getNumEntries();

};


# endif