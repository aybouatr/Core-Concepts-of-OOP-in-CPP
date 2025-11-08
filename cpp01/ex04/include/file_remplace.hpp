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
    std::string _my_replace(std::string buffer, const std::string search, const std::string replace);
    void _Read();


public:

    file_remplace(const std::string &fileName);

    bool remplace(const std::string &search, const std::string &replace);
   
    ~file_remplace();
};

#endif
