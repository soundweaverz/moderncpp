#include <string>
#include <iostream> // cout, ostream
#include <fstream>  // ofstream
#include <sstream>  // ostringstream

using std::string, std::cout;

struct Person
{
    string name_;
    int alter_;
    string ort_;
    void drucke(std::ostream& os);
};

void Person::drucke(std::ostream& os)
{
    os << name_ << " (" << alter_
        << ") aus " << ort_;
}

int main()
{
    Person karl {"Karl", 12, "Stetten"};
    karl.drucke(cout);                      // auf dem Bildschirm
    cout << "\n";
    std::ofstream datei {"personen.txt"};
    karl.drucke(datei);                     // in eine Datei
    // automatischer Test
    std::ostringstream oss {};              // schreibt in einen string
    karl.drucke(oss);
    if (oss.str() == "Karl (12) aus Stetten")
    {
        cout << "ok\n";
    }
    else
    {
        cout << "Fehler in Person::drucke!\n";
        return 1;                           // Fehler nach außen weiterleiten
    }

    return 0;
}