#include <string>

using std::string;

struct Person
{
    string name_;
    int alter_;
    string ort_;

    Person(string n = "N.N.", int a = 18, string o = "Berlin"):
        name_(n), alter_(a), ort_(o) { }
};


int main()
{
    return 0;
}