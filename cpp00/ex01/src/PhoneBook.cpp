#include "../include/PhoneBook.hpp"
#include <iostream>


PhoneBook::PhoneBook()
{
	_num_entries = 0;
    _full = false;
}

PhoneBook::~PhoneBook()
{
	
}

void PhoneBook::ShowInstruction()
{
	std::cout << "\033[KEnter your command [ADD, SEARCH, EXIT]:" << std::endl;
}

std::string PhoneBook::get_corrrect_input_string(const std::string& Message)
{
    std::string input;
    bool first_try = true;
	bool has_printable = false;
	
    std::cout << Message << std::endl;
    while (true)
    {
        if (!std::getline(std::cin, input))
        {
			if (std::cin.eof() == true)
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
            std::cin.clear();
            continue;
        }
        if (input.empty())
        {
            if (!first_try)
                std::cout << Message << std::endl;
            first_try = false;
            continue;
        }
        for (int i = 0 ; i < (int )input.length() ;i++)
        {
            if (input[i] != '	' && input[i]  != '\r' && input[i] != '\t' && input[i] != ' ' )
            {
                has_printable = true;
                break;
            }
        }
        if (!has_printable)
        {
            std::cout << "Input contains no printable characters. Try again." << std::endl;
            continue;
        }
        break;
    }
    return input;
}

void  PhoneBook::set_information()
{
	std::string _Last_name;
	std::string _First_name;
	std::string _Nick_name;
	std::string _Phone_number;
	std::string _Darkest_secret;
    std::string input;

	
	_First_name =  PhoneBook::get_corrrect_input_string("Please Enter First Name");
	_Last_name =  PhoneBook::get_corrrect_input_string("Please Enter Last Name");
	_Nick_name =  PhoneBook::get_corrrect_input_string("Please Enter Nick Name");
	_Phone_number =  PhoneBook::get_corrrect_input_string("Please Enter Phone Number");
	_Darkest_secret =  PhoneBook::get_corrrect_input_string("Please Enter Darkest Secret");

    if (!this->_full && this->_num_entries < 8)
    {
	    contacts[_num_entries].set_Contact_information(_First_name,_Last_name,_Nick_name,_Phone_number,_Darkest_secret);
        if (this->_num_entries < 8)
		{
            this->_num_entries++;
			std::cout << "\033[36m----------------------------\033[0m" << std::endl;
        	std::cout << "\033[32mSAVED SUCCESSFULLY.\033[0m" << std::endl;
        	std::cout << "\033[36m----------------------------\033[0m" << std::endl;
		}
        else
            this->_full = true;
	    
    }
    else
    {
        std::cout << "\033[31mYour phonebook is full.\n" << "If you want to add a new contact, I am going to delete the first contact I stored, index #1.\033[0m\n";
    	std::cout << "\033[33mIf you want to proceed, press '1' and confirm with 'enter',\n" << "if not press anything but '1' and confirm with 'enter' to go back to main menu.\033[0m\n";
    	std::cout << "\033[32mYour choice: \033[0m";
		getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
			std::exit(0);
		}
		else if (input.compare("1") == 0)
		{
			for (int i = 1; i < 8; i++)
				this->contacts[i - 1] = this->contacts[i];
			std::cout << "This is your contact #8" << std::endl;
			this->contacts[7].set_Contact_information(_First_name,_Last_name,_Nick_name,_Phone_number,_Darkest_secret);
		}
		else
			std::cout << "Back to main menu without deleting and creating a contact." << std::endl;
    }

}


void	PhoneBook::get_information() const
{
	int	index;

	if (this->_num_entries == 0)
		std::cout << "\033[31mPlease add at least one contact before searching.\033[0m" << std::endl;
	else
	{
		std::string input;
		std::cout << "Please tell me which contact index i should show you. (0 to quit searching)\nIndex: ";
		while (!(std::getline(std::cin, input)) || input.length() > 1 || input.compare("0") < 0 || input.compare("8") > 0 
				|| (std::atoi(input.c_str()) -1 >= this->_num_entries && this->_full == false)       )
		{
			if (std::cin.eof() == true)
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (input.length() > 1 || input.compare("0") < 0 || input.compare("8") > 0)
			{
				std::cin.clear();
				std::cout << "\033[31mOnly digits in range of 1 to 8 are allowed.\033[0m\n";
				std::cout << "Please tell me which contact i should show you. (0 to quit searching)\nIndex: ";
			}
			else if (std::atoi(input.c_str()) - 1 >= this->_num_entries && this->_full == false)
			{
				std::cout << "\033[33mYou only have " << this->_num_entries << " Contacts saved.\033[0m" << std::endl;
				std::cin.clear();
				std::cout << "Please tell me which contact i should show you. (0 to quit searching)\nIndex: ";
			}
        }
		index = std::atoi(input.c_str());
		if (index > 0)
		{

            std::cout << "\033[36m|-------------------------------------------\033[0m" << std::endl;
            std::cout << "\033[33m| Index          : \033[0m" << "\033[32m" << index << "\033[0m" << std::endl;
            std::cout << "\033[33m| First Name     : \033[0m" << "\033[32m" << contacts[index - 1].getFirst_name() << "\033[0m" << std::endl;
            std::cout << "\033[33m| Last Name      : \033[0m" << "\033[32m" << contacts[index - 1].getLastName() << "\033[0m" << std::endl;
            std::cout << "\033[33m| Nickname       : \033[0m" << "\033[32m" << contacts[index - 1].getNick_name() << "\033[0m" << std::endl;
            std::cout << "\033[33m| Phone Number   : \033[0m"  << "\033[32m" << contacts[index - 1].getPhone_number() << "\033[0m" << std::endl;
            std::cout << "\033[33m| Darkest Secret : \033[0m" << "\033[32m" << contacts[index - 1].getDarkest_secret() << "\033[0m" << std::endl;
            std::cout << "\033[36m|-------------------------------------------\033[0m" << std::endl;
		}
		else
			std::cout << "Exiting search mode now." << std::endl;
	}
}


int PhoneBook::getNumEntries()
{
	return (this->_num_entries);
}