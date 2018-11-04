#include <iostream>                             // cout, cerr
#include <vector>
#include <string>
#include <fstream>                              // ifstream
#include <stdexcept>                            // invalid_argument

using std::vector, std::string, std::cout, std::cerr, std::ifstream;

size_t zaehleWoerter(const string& filename)    // 0 oder größer
{
    ifstream file {};                           // ungeöffnet erzeugen
    // anmelden für Exceptions
    file.exceptions(ifstream::failbit | ifstream::badbit);
    file.open(filename);                        // könnte eine Exceptions auslösen

    size_t count = 0;
    string wort;

    file.exceptions(ifstream::badbit);          // EOF keine Exception mehr
    while(!file.eof())                          // noch nicht am Ende
    {
        file >> wort;
        ++ count;
    }

    return count - 1;                           // -1: am EOF noch ein Wort eingelesen
}

void process(const vector<string>& args)
{
    if (args.size() == 0)                       // process erwartet Parameter
    {
        throw std::invalid_argument             // auslösen
        {
            "Kommandozeilenargument fehlt"
        };
    }
    else
    {
        for (const string filename : args)
        {
            cout << filename << ": " << zaehleWoerter(filename) << std::endl;
        }
    }
}

int main(int argc, const char* argv[])
{
    try                                         // Block mit Fehlerbehandlungen
    {
        process(
            vector<string> {argv + 1, argv + argc}  // const char* [] nach vector<string>
        );
        
        return 0;
    }
    catch(std::exception &exc)                  // Fehlerbehandlung
    {
        cerr << "Es trat ein Fehler auf: " << exc.what() << "\n";
        return 1;
    }
}