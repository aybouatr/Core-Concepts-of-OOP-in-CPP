/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:39:03 by aybouatr          #+#    #+#             */
/*   Updated: 2025/12/01 14:39:05 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap("Default_Frag")
{
    hitPoints    = 100;
    energyPoints = 100;
    attackDamage = 30;

    std::cout << "FragTrap " << name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const std::string& n) : ClapTrap(n)
{
    hitPoints    = 100;
    energyPoints = 100;
    attackDamage = 30;

    std::cout << "FragTrap " << name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructed!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called!" << std::endl;
    return *this;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a positive HIGH FIVE! " << std::endl;
}
