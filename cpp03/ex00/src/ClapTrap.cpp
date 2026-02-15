/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:26:30 by aybouatr          #+#    #+#             */
/*   Updated: 2025/12/01 09:26:32 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"



ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap " << this->name << " copy constructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other) 
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destructed." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " has no hit points left and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " has no energy points left and cannot attack!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;

    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! HP is now " << hitPoints << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points left and cannot be repaired!" << std::endl;
        return;    
    }
    if (energyPoints <= 0) 
    {
        std::cout << "ClapTrap " << name << " has no energy points left and cannot repair!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for "
              << amount << " hit points! HP is now " << hitPoints << "." << std::endl;
}

