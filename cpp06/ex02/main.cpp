#include "include/Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>



Base* generate(void) 
{
    int r = std::rand() % 3;

    if (r == 0) 
    {
        std::cout << "Generated: A\n";
        return new A;
    } 
    else if (r == 1) 
    {
        std::cout << "Generated: B\n";
        return new B;
    } 
    else 
    {
        std::cout << "Generated: C\n";
        return new C;
    }
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identified (pointer): A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified (pointer): B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified (pointer): C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p) 
{
    try 
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Identified (reference): A\n";
        return;
    }
    catch (...)
    {
        // std::cout << "Failed to identify as A\n";
    }

    try 
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Identified (reference): B\n";
        return;
    } catch (...)
    {
        // std::cout << "Failed to identify as B\n";
    }

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Identified (reference): C\n";
        return;
    } 
    catch (...)
    {
        // std::cout << "Failed to identify as C\n";
    }

     std::cout << "Unknown type\n";
  
}


int main() 
{
    std::srand(std::time(0));

    Base* obj = generate();

    std::cout << "\nIdentify using pointer:" << std::endl;
    identify(obj);

    std::cout << "\nIdentify using reference:" << std::endl;
    identify(*obj);

    delete obj;
    return 0;
}