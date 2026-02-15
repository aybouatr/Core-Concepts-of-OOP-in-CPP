/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:44:49 by aybouatr          #+#    #+#             */
/*   Updated: 2025/12/01 09:44:52 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"
#include "include/ClapTrap.hpp"



int main()
{
   
    ClapTrap Sv("salim");

    
    Sv.attack("ali");
    Sv.takeDamage(2);
    Sv.attack("ayoub");
    Sv.attack("ali");

    Sv.attack("ayoub");
    Sv.attack("ali");


    return 0;
}
