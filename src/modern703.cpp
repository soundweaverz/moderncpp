#include <iostream>

void print_val8(int n)                  // Parameter als Wert
{
    std::cout << n << " ";
    n = 8;                              // setzt Paramter auf 8
    std::cout << n << "\n";
}

int main()
{
    int x = 5;
    print_val8(x);                      // x als Wert: druckt 5, dann 8
    std::cout << x << "\n";             // x ist unverändert 5
    print_val8(42);                     // 42 als Wert: druckt 42, dann 8

    return 0;
}