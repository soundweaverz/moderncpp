#include <string>
#include <vector>
#include <iostream>

using std::string, std::cout;

struct Person
{
    string name_;
    int alter_;
    string ort_;
    // fungiert als Defaultkonstruktor
    Person(string n = "N.N.", int a = 18, string o = "Berlin"):
        name_(n), alter_(a), ort_(o) { }
};


int main()
{
    std::vector<Person> personen{};         // zunächst leer
    personen.resize(5);                     // auf fünf "leere" Personen erweitern
    cout << personen[3].ort_ << "\n";       // Ausgabe: Berlin

    return 0;
}