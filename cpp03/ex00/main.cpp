/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:26:00 by aybouatr          #+#    #+#             */
/*   Updated: 2025/12/01 09:26:03 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

int main()
{
    ClapTrap a("Jack");
    ClapTrap b("Tom");

    a.attack("Tom");
    b.takeDamage(20);
    a.beRepaired(5);

    b.takeDamage(20);

    return 0;
}
