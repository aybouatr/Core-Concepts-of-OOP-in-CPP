/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:31:17 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/15 09:31:20 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
#define Contact_HPP

#include <string>
#include <iomanip>
#include <cstdlib>



class Contact
{
	private:
		std::string _Last_name;
		std::string _First_name;
		std::string _Nick_name;
		std::string _Phone_number;
		std::string _Darkest_secret;
		time_t 		_Created;

	public:

		Contact();
		~Contact();
	
		std::string	getLastName() const;
		std::string	getFirst_name() const;
		std::string	getNick_name() const;
		std::string	getPhone_number() const;
		std::string	getDarkest_secret() const;
		void set_Contact_information(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string darkest_secret);
		time_t		getCreated() const;
};


# endif
