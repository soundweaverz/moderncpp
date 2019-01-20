#include <iostream>
#include <string>

void berechne(int n)
{
    using namespace std;

    /* Teiler ausgeben */
    cout << "Teiler von " << n << " sind:\n";
    for (int teiler = 1; teiler <= n; ++teiler)
    {
        if (n % teiler == 0)
        {
            cout << teiler << ", ";
        }
    }
    cout << endl;
}

int main(int argc, const char* argv[])
{
    /* Zahl ermitteln */
    int wert = 0;
    if (argc <= 1)
    {
        std::cout << "Geben Sie eine Zahl ein: ";
        std::cin >> wert;
        if (!std::cin)
        {
            return 1;
        }
    }
    else
    {
        wert = std::stoi(argv[1]);
    }
    berechne(wert);
    return 0;
}
