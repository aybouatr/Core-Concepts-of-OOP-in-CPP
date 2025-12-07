#pragma once

#include <string>
#include <iostream>

class Brain
{
private :

    int nbrIdeas;
    std::string ideas[100];

public:

    Brain();
    ~Brain();
    Brain(const Brain &other);
    Brain& operator=(const Brain &other);
    void setIdea(const std::string idea,const int index);
    std::string getIdea(const int index);

};

