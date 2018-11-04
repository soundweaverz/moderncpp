#include <string>
#include <iostream>

using std::string, std::cout;

struct Person                               // definiert den neuen Typ Person
{
    string name_;
    int alter_;
    string ort_;                    
};

string gruss(Person * const p)              // implizierter Parameter explizit gemacht
{
    return "Hallo " + p->name_ + " aus " + p->ort_;
}

int main()
{
    Person anna {"Anna", 33, "Hof"};
    Person nina {"Nina", 22, "Wyk"};
    gruss(&anna);
    gruss(&nina);
    
    return 0;
}