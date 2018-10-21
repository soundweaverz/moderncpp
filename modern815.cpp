#include <iostream>                     // cout
#include <string>
#include <vector>

void rechner(std::ostream& out, std::string input)
{
    std::vector<int> stapel {};
    for (char c : input)
    {
        if (c >= '0' && c <= '9')
        {
            stapel.push_back(c - '0');  // Zahlenwert des Zeichens
            continue;                   // nächste Schleifeniteration
        }
        int top = 0;
        int second = 0;
        switch (c)                      // Bedingung auf Zeichen
        {
            case '+':
                top = stapel.back(); stapel.pop_back();
                second = stapel.back(); stapel.pop_back();
                stapel.push_back(second + top);
                break;
            case '-':
                top = stapel.back(); stapel.pop_back();
                second = stapel.back(); stapel.pop_back();
                stapel.push_back(second - top);
                break;
            case '*':
                top = stapel.back(); stapel.pop_back();
                second = stapel.back(); stapel.pop_back();
                stapel.push_back(second * top);
                break;
            case '=':
                for (int elem : stapel)
                {
                    out << elem;
                }
                break;
            case ' ':
                break;
            default:
                out << "\n'" << c << "' verstehe ich nicht.\n";
        } /* switch */
    } /* for c */
}

int main(int argc, const char* argv[])
{
    if(argc > 1)
    {
        rechner(std::cout, argv[1]);
    }
    else
    {
        // 3 + 4 * 5 + 6 mit Punkt- vor Strichrechnung ergibt 29
        rechner(std::cout, "345*+6+=");
    }
}