#include <vector>
#include <algorithm>                        // count_if
#include <numeric>                          // iota
#include <iostream>

bool even(int n)
{
    return n % 2 == 0;                      // Test auf gerade
}

int main()
{
    std::vector<int> data(100);             // 100 x null
    std::iota(data.begin(), data.end(), 0); // 0, 1, 2, ..., 99
    // zählt gerade Zeichen
    std::cout <<
        std::count_if(data.begin(), data.end(), even);

    return 0;
}
