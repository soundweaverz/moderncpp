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
    ostream& drucke(ostream& os)                // Methode inline definiert
    {
        return os << name_ << " (" << alter_
            << ") aus " << ort_;
    };
};

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