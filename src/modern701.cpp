#include <iostream>                                                 // cout
#include <cmath>                                                    // sin
#include <string>
#include <vector>

int main()
{
    std::cout << "sin(0.0): " << sin(0.0) << "\n";                  // Aufruf von sin() mit Literal
    double winkel = 3.1415/2;
    std::cout << "sin(" << winkel << "): " << sin(winkel) << "\n";  // Aufruf mit Variable
    std::string name = "Han Solo";
    std::cout << name.length() << "\n";                             /* Aufruf einer Methode
                                                                     * konzeptionell wie length(name) */
    std::vector<int> data {};
    data.push_back(5);                                              // weiterer Methodenaufruf mit Parameter
    data.push_back(10);
    std::cout << data.back() << " ";
    data.pop_back();
    std::cout << data.back() << "\n";
    data.pop_back();

    return 0;
}