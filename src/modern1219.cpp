#include <string>

using std::string;

class Person
{
    string name_;
    int alter_;
    string ort_;

    public:
        Person(string n, int a, string o)
            : name_{n}, alter_{a}, ort_{o} { }
        void drucke();
};

int main()
{
    return 0;
}
