/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:26:12 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/15 09:26:36 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main(int ac,char** av)
{
    int i;
    int j;

    i = 0;
    if (ac > 1)
    {
        while (av[++i] != NULL)
        {
            j = -1;
            while (av[i][++j])
                av[i][j] = (char )toupper(av[i][j]);
            std::cout << av[i];
        }
        std::cout << std::endl;
    }
    else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
