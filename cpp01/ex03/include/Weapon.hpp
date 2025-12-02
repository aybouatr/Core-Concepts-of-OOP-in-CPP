/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:11:10 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/16 10:11:13 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>



class Weapon
{
	private:
		std::string	_type;

	public:

		Weapon(const std::string &weapon);
		~Weapon();
		std::string getType() const;
		void setType(const std::string &weapon);

};

# endif
