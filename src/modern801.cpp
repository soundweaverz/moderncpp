#include <iostream>                         // cout
#include <vector>                           // Container vector
#include <string>                           // stoi

std::vector<int> prims {2};                 // neuer Vector mit Initialisierung

int eingabeBis(int argc, const char* argv[])
{
    /* Zahl ermitteln */
    int bis = 0;                            // neue Variable einführen
    if (argc <= 1)                          // if-Anweisung mit then- und else-Block
    {
        std::cout << "Bis wohin wollen Sie Primzahlen berechnen?: ";
        if (!(std::cin >> bis))             // prüfen des Rückgabewerts
        {
            return -1;                      // Fehler bei Benutzereingabe
        }
    }
    else                                    // else-Teil der if-Anweisung
    {
        bis = std::stoi(argv[1]);
    }
    return bis;                             // Eingabe zurückliefern
}

bool testeObPrim(int n)
{
    /* prims muss aufsteigend sortiert sein */
    for (int teil : prims)                  // bereichsbasierte for-Schleife
    {
        if (teil*teil > n)                  // zu groß, um überhaupt Teiler zu sein?
        {
            return true;                    // ... dann innere Schleife vorzeitig beenden
        }
        if (n % teil == 0)                  // ist Teiler?
        {
            return false;                   // ... dann raus
        }
    }
    return true;                            // kein Teiler gefunden
}

void berechnePrimsBis(int bis)
{
    /* Prims-Berechnung */
    /* vector muss an dieser Stelle {2} enthalten */
    for (int n = 3; n < bis; n = n + 2)     // Standard-for-Schleife
    {
        if (testeObPrim(n))
        {
            prims.push_back(n);             // ist prim! merken als Teiler und Ergebnis
        }
    }
}

void ausgabePrims()
{
    for (int prim : prims)                  // bereichsbasiert, über alle Elemente
    {
        std::cout << prim << " ";
    }
    std::cout << "\n";
}

int main(int argc, const char* argv[])
{
    int bis = eingabeBis(argc, argv);       // deklariert Variable
    if (bis < 2)
    {
        return 1;                           // Raus aus main mit "nicht-ok"-Wert.
    }
    berechnePrimsBis(bis);
    ausgabePrims();
    return 0;
}