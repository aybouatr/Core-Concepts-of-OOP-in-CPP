/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 09:13:24 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/16 09:13:27 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/Zombie.hpp"

Zombie::Zombie()
{
	
}

Zombie::~Zombie()
{
	std::cout << "Zombie \"" << _name << "\" destroyed" << std::endl;
}

void Zombie::set_name(std::string name)
{
	_name = name;
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
