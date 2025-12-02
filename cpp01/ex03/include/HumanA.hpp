/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:10:39 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/16 10:10:42 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
# define HUMANA_HPP


#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;
	public:
	
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void attack(void);
		
};

# endif
