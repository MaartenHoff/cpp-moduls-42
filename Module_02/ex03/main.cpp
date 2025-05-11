#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point p(-1, 1);
    
    if (bsp(a, b, c, p))
        std::cout << "Inside triangle" << std::endl;
    else
        std::cout << "Outside triangle" << std::endl;
    return (0);
}
