#include <iostream>

int add(int n = 0, int m = 0, int o = 0, int p = 0, int q = 0)
{
    return n + m + o + p + q;
}

int main()
{
    std::cout << add(1, 2, 3, 4, 5) << "\n";
    std::cout << add(1, 2, 3, 4) << "\n";
    std::cout << add(1, 2, 3) << "\n";
    std::cout << add(1, 2) << "\n";
    std::cout << add(1) << "\n";
    std::cout << add() << "\n";

    return 0;
}