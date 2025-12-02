/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:56:32 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/17 11:56:35 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Harl.hpp"


int main (int argc, char **argv)
{
	std::string level;
	Harl harl;
	
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments!\n";
		return (0);
	}
	level = argv[1];
	harl.complain(level);
	return (0);
}
