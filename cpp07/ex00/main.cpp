#include "include/whatever.hpp"



int main()
{
    int a = 2;
    int b = 3;

    std::cout << "\n\na = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << whatever::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << whatever::max(a, b) << std::endl;
    whatever::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "\n\nc = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << whatever::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << whatever::max(c, d) << std::endl;
    whatever::swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;

    double e = 1.5;
    double f = 2.5;

    std::cout << "\n\ne = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << whatever::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << whatever::max(e, f) << std::endl;
    whatever::swap(e, f);
    std::cout << "After swap: e = " << e << ", f = " << f << std::endl; 

    return 0;
}