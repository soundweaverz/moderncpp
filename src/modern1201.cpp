#include <string>
#include <iostream>                         // cout

using std::string, std::cout;

struct Person                               // definiert den neuen Typ Person
{
    string name_;
    int alter_;
    string ort_;
};                                          // abschließendes Semikolon 

void drucke(Person p)                       // ganze Person als ein Parameter
{
    cout << p.name_ << " (" << p.alter_     // Zugriff per Punkt
        << ") aus " << p.ort_ << "\n";
}

int main()
{
    Person otto {"Otto", 45, "Kassel"};     // Initialisierung
    drucke(otto);

    return 0;
}