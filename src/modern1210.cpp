#include <string>
#include <iostream> // cout, ostream
#include <fstream>  // ofstream
#include <sstream>  // ostringstream

using std::string, std::cout, std::ostream;

struct Person
{
    string name_;
    int alter_;
    string ort_;
    Person();                                   // Konstruktor deklarieren
    ostream& drucke(ostream& os)
    {
        return os << name_ << " (" << alter_
            << ") aus " << ort_;
    };
};

Person::Person()
    : name_{"kein Name"}                        // Initialisierungswert für name_
    , alter_{-1}                                // Initialisierungswert für alter_
    , ort_{"kein Ort"}                          // Initialisierungswert für ort_
{ }                                             // leerer Funktionskörper

std::ostream& operator<<(std::ostream& os, Person p)
{
    return p.drucke(os);
}

int main()
{
    Person paul {"Paul", 23, "Dresden"};
    cout << "Sie sind " << paul << ", richtig?\n";

    return 0;
}