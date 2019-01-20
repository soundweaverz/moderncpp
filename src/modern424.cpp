#include <iostream>

void printBin(int x)
{
    while(x > 0)        // fertig?
    {
        int a = x / 2;  // Division durch 2
        int b = x % 2;  // Modulo, Rest der Division
        std::cout << x << " / 2 = " << a << ", Rest " << b << std::endl;    // Ausgabe
        x = a;
    }
}

int main()
{
    printBin(412);
    return 0;
}
