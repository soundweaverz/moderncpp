#include <vector>
#include <iostream>

int main()
{
    std::vector<int> qus {1, 4, 9, 16, 25};
    for (int idx = 0; idx < qus.size(); ++idx)
    {
        std::cout << qus [idx] << " ";
    }
    std::cout << std::endl;

    return 0;
}
