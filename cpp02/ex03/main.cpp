#include "include/Point.hpp"
// #include "src/bsp.cpp"
#include <iostream>

int main()
{
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);

    Point inside(2.0f, 2.0f);
    Point outside(5.0f, 1.0f);
    Point edge(2.0f, 0.0f);
    Point vertex(0.0f, 0.0f);

    std::cout << "Inside: " << bsp(a, b, c, inside) << "\n";
    std::cout << "Outside: " << bsp(a, b, c, outside) << "\n";
    std::cout << "On edge: " << bsp(a, b, c, edge) << "\n";
    std::cout << "Vertex: " << bsp(a, b, c, vertex) << "\n";
}
