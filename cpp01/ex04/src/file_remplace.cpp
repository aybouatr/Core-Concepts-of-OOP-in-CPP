#include "../include/file_remplace.hpp"


void file_remplace::_Read()
{
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
    infile.open(fileName.c_str());
    if (!infile.is_open())
        throw std::runtime_error("Failed to open file: " + fileName);
    _Read();
}

bool file_remplace::remplace(const std::string &search, const std::string &replace)
{
    outfile.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
    if (!outfile.is_open())
        throw std::runtime_error("Failed to open file: " + filename + ".replace");
    contentFile = _my_replace(contentFile, search, replace);
    outfile << contentFile;
    outfile.close();
    return true;
}

 file_remplace::~file_remplace()
{
        
}