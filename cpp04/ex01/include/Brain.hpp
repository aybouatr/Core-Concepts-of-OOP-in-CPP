#pragma once


class Brain
{
private :
    const static int nbrIdeas;
    std::string arr[nbrIdeas];

public:

    Brain();
    ~Brain();
    void Brain(cons Brain &B);
    Brain& operator=(const Brain &B);
    void setIdea(const std::string idea,const int index);
    std::string getIdea(const int index);

};

Brain::Brain()
{
    std::cout << "Brain Call default Constarctor" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Call  Destarctor" << std::endl;
}

