/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_remplace.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:49:17 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/17 11:49:20 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_REMPLACE_HPP
#define FILE_REMPLACE_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class file_remplace
{
private:

    std::ifstream infile;
    std::ofstream outfile;
    std::string filename;
    std::string contentFile;
    bool flagError;
    std::string _my_replace(std::string buffer, const std::string search, const std::string replace);
    void _Read();


public:

    file_remplace(const std::string &fileName);
    bool remplace(const std::string &search, const std::string &replace);
    ~file_remplace();
};

#endif
