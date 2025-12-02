/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:38:00 by aybouatr          #+#    #+#             */
/*   Updated: 2025/12/01 14:38:02 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

int main()
{
    ClapTrap a("Jack");
    ClapTrap b("Tom");

    a.attack("Tom");

    b.takeDamage();

    a.beRepaired(5);

    for (int i = 0; i < 11; i++)
        a.attack("Tom");

    b.takeDamage(20);

    return 0;
}
