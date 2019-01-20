#include <iostream>

void print_ref8(int& n)                  // Parameter als Wert
{
    std::cout << n << " ";
    n = 8;                              // setzt Paramter auf 8
    std::cout << n << "\n";
}

int main()
{
    int x = 5;
    print_ref8(x);                      // x als Wert: druckt 5, dann 8
    std::cout << x << "\n";             // x ist nun 8

    return 0;
}