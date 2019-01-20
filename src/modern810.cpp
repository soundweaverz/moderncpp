#include <iostream>             // cin
#include <string>

int main()
{
    std::string line;
    do                          // mindestens einmal getline ausführen
    {
        std::getline(std::cin, line);
        if(!std::cin)           // Fehler oder Dateiende
        {
            break;
        }
    }
    while (line != "quit");     // Ende bei bestimmter Eingabe
}