/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:48:45 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/17 11:48:47 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/file_remplace.hpp"

int main(int ac,char* av[])
{
    std::string content_file;

    if (ac != 4)
    {
        std::cout << "please fix argument !" << std::endl ;
        return (0);
    }
    if (std::string(av[1]).empty() || std::string(av[2]).empty())
    {
        std::cout << "Error: Arguments cannot be empty!" << std::endl;
        return 1;
    }
    file_remplace *f = new file_remplace(av[1]);
    f->remplace(av[2],av[3]);
    delete f;
}
