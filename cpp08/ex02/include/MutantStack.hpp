#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


class MutantStack : public std::stack<int>
{
private:
    Stack<int> _stack;
    
public:
    MutantStack();
    ~MutantStack();
};

MutantStack::MutantStack()
{
}

MutantStack::~MutantStack()
{
}






#endif