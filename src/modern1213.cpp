#include <string>

using std::string;

struct Person
{
    string name_;
    int alter_;
    string ort_;

    Person(string n, int a, string o):                      // delegierte Konstruktor
        name_{n}, alter_{a}, ort_{o} { }                    // ... ausimplementiert
    Person(): Person{"kein Name", -1, "kein Ort"} { }       // delegierend
    Person(string n, int a): Person{n, a, "kein Ort"} { }   // delegierend
    Person(string n): Person{n, -1, "kein Ort"} { }         // delegierend
};


int main()
{
    return 0;
}