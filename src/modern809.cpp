#include <iostream>

int main()
{
    /* Summiere 1 bis 100 auf */
    int summe = 0;
    int zahl = 1;
    while(zahl <= 100)          // Bedingung
    {                           // Block, der wiederholt ausgeführt wird
        summe += zahl;          // fürs Ergebnis
        zahl += 1;              // nächste Zahl
    }                           // Ende des wiederholten Blocks
    std::cout << summe << std::endl;

    return 0;
}