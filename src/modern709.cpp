#include <iostream>

void print(int wert)
{
    std::cout << "int-Wert: " << wert << "\n";
}
void print(double wert)
{
    std::cout << "double-Wert: " << wert << "\n";
}
void print(int w1, double w2)
{
    std::cout << "Werte: " << w1 << ", " << w2 << "\n";
}

int add(int n, int m)
{
    return n + m;
}
double add(double a, double b)
{
    return a + b;
}

int main()
{
    print(add(3, 4));           // add(int, int) und print(int)
    print(add(3.25f, 1.5f));    // add(double, double) und print(double)
    print(7, 3.25);             // print(int, double)

    return 0;
}