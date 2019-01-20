#include <iostream>
#include <map>

int fib(int n)
{
    static std::map<int, int> table {};
    table[n] = n < 2 ? 1 : table[n-2] + table[n-1];
    return table[n];
}

int main()
{
    std::cout << "Wie viele Fibonacci-Zahlen? ";
    int n = 0;
    std::cin >> n;
    for (int i = 0; i <= n; ++i)
    {
        std::cout << "fib(" << i << ")=" << fib(i) << "\n" << "\n";
    }
}