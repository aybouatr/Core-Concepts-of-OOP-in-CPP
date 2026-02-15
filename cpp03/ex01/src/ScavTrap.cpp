/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:45:29 by aybouatr          #+#    #+#             */
/*   Updated: 2025/12/01 09:45:31 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name <<" constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap Copy assignment operator called\n";
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << name << "\n";
}

void ScavTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        --energyPoints;
        std::cout << "ScavTrap " << name << " ferociously attacks "
                  << target << ", dealing " << attackDamage
                  << " points of damage!\n";
    }
    else
        std::cout << "ScavTrap " << name << " is unable to attack.\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " has entered Gate Keeper mode!\n";
}
