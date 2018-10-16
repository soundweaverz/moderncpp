#include <iostream>

int main()
{
    /* Summiere 1 bis 100 auf */
    int summe = 0;
    for (int zahl = 1; zahl <= 100; zahl += 1)  // kompakt
    {
        summe += zahl;                          // fürs Ergebnis
    }
    std::cout << summe << std::endl;
}