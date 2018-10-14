#include <vector>
#include <iostream>

int main()
{
    std::vector<int> quadrate {1, 4, 9, 16, 25};
    for (int zahl : quadrate)
    {
        std::cout << zahl << " ";
}
    std::cout << std::endl;

    return 0;
}
