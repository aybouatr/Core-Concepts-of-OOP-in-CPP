/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 09:06:55 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/16 09:06:58 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie
{
private:
	std::string _name;
public:
	Zombie(std::string name);
	~Zombie();

	void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

# endif
