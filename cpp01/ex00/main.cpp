/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 09:06:34 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/16 09:06:38 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"


int main(void)
{
	
    Zombie *newZombie1;
	
	newZombie1 = newZombie("New Zombie");
	
    newZombie1->announce();

	randomChump("Random Zombie");

	delete newZombie1;
	
    return (0);
}
