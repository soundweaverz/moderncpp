#include <iostream>
#include <iomanip>     //fixed, setprecision

int main()
{
    std::cout << std::setprecision(30) << std::fixed;    // immer 30 Stellen ausgeben
    std::cout << 1.111222333444555666777888999f << "\n";    // float-Literal
    std::cout << 1.111222333444555666777888999 << "\n";     // double ist Default
    std::cout << 1.111222333444555666777888999d << "\n";    // double-Literal
    std::cout << 1.111222333444555666777888999L << "\n";    // long double
}
