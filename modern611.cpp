#include <iostream>
#include <vector>

int main()
{
    std::vector<int> qus {1, 4, 9, 16, 25};
    for (auto it = qus.begin(); it != qus.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
