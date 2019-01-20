#include <iostream>

int fib(int n)
{
    return n < 2 ? 1 : fib(n-2) + fib(n-1);
}

int main()
{
    std::cout << "Die wievielte Fibonacci-Zahl? ";
    int n = 0;
    std::cin >> n;
    std::cout << "fib(" << n << ")=" << fib(n) << "\n" << "\n";
}
