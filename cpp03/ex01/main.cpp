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
#include <iostream>



int main()
{
   
    ClapTrap * Sv = new ScavTrap;

    
    Sv->attack("ali");

    Sv->attack("ayoub");
    Sv->attack("ali");

    Sv->attack("ayoub");
    Sv->attack("ali");

    delete Sv;

    return 0;
}
