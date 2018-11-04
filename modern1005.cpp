#include <iostream>                     // cout
#include <string>

using std::string, std::to_string, std::cout;

void fehlerAusloesen(int fehlerfall)
{
    try
    {
        if (fehlerfall < 10)
        {
            throw static_cast<int>(fehlerfall);
        }
        else if (fehlerfall < 20)
        {
            throw 1.0 / (fehlerfall - 10.0);
        }
        else
        {
            throw string {"Fehler " + to_string(fehlerfall)};
        }
    }
    catch (int eval)
    {
        cout << "int-Fehler: " << eval << "\n";
    }
    catch (double eval)
    {
        cout << "double-Fehler: " << eval << "\n";
    }
    catch (string eval)
    {
        cout << "string-Fehler: " << eval << "\n";
    }
}

int main()
{
    fehlerAusloesen(3);                 // int-Fehler: 3
    fehlerAusloesen(14);                // Ausgabe: double-Fehler: 0.25
    fehlerAusloesen(50);                // Ausgabe: string-Fehler: Fehler 50

    return 0;
}