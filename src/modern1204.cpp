#include <string>
#include <iostream>

using std::string, std::cout;

struct Person                               // definiert den neuen Typ Person
{
    string name_;
    int alter_;
    string ort_;
    string gruss();                         
};

string Person::gruss()
{
    return "Hallo " + this->name_ + " aus " + this->ort_;
}

int main()
{
    Person anna {"Anna", 33, "Hof"};
    Person nina {"Nina", 22, "Wyk"};
    anna.gruss();
    nina.gruss();
    
    return 0;
}