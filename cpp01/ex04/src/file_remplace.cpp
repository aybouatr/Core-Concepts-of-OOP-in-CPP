/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_remplace.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:49:44 by aybouatr          #+#    #+#             */
/*   Updated: 2025/11/17 11:49:47 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/file_remplace.hpp"


void file_remplace::_Read()
{
    if (flagError)
        return;
    std::string line;
    while (std::getline(infile, line))
    {
        contentFile += line;
        contentFile += '\n';
    }
    infile.close();
}

std::string file_remplace::_my_replace(std::string buffer, const std::string search, const std::string replace)
{
    if (flagError)
        return buffer;
    size_t pos_search = buffer.find(search);
    while (pos_search != std::string::npos)
    {
        buffer.erase(pos_search, search.length());
        buffer.insert(pos_search, replace);
        pos_search = buffer.find(search, pos_search + replace.length());
    }
    return buffer;
}

file_remplace::file_remplace(const std::string &fileName)
{
    filename = fileName;
    flagError = false;
    infile.open(fileName.c_str());
    if (!infile.is_open())
    {
        std::cout << "fails open file " + fileName  << std::endl;
        flagError = true;
        return ;
    }
    _Read();
}

bool file_remplace::remplace(const std::string &search, const std::string &replace)
{
    if (flagError)
        return false;
    outfile.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
    if (!outfile.is_open())
    {
        std::cout << "fails open file " + filename + ".replace"  << std::endl; 
        return (false);
    }
    contentFile = _my_replace(contentFile, search, replace);
    outfile << contentFile;
    return true;
}

 file_remplace::~file_remplace()
{
    outfile.close();
}
