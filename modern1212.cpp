#include <string>

using std::string;

struct Person
{
    string name_ = "kein Name";
    int alter_ = -1;
    string ort_ = "kein Ort";
    Person() {}
    Person(string n, int a, string o):
        name_{n}, alter_{a}, ort_{o} { }
    Person(string n, int a):
        name_{n}, alter_{a} { }
    Person(string n):
        name_{n} { }
};


int main()
{
    return 0;
}