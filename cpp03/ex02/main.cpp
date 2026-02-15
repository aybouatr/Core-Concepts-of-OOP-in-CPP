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

#include "include/FragTrap.hpp"

int main()
{

   FragTrap B("ali");

    B.takeDamage(21);
    B.attack("mohammed");
    B.highFivesGuys();

    return 0;
}
