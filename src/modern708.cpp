#include <iostream>
#include <iomanip>                                  // setprecision

void prints(short s, int i, float f, double d)
{
    std::cout << "short: " << s << " "
        << "int: " << i << " "
        << std::setprecision(20)                    // drucke 20 Stellen, wenn nötig
        << "float: " << f << " "
        << "double: " << d << "\n";
    std::cout << sizeof(long) << " " << sizeof(long long) << std::endl;
}

int main()
{
    int mill = 1000*1000;                           // 1 Million
    prints(mill, mill, mill, mill);                 // short läuft über
    
    long long bill = 1000LL*1000LL*1000LL*1000LL;   // 1 Billion
    prints(bill, bill, bill, bill);                 // sogar int läuft über, float wird ungenau

    float drei = 3.75f;
    prints(drei, drei, drei, drei);                 // Nachkommastellen gehen verloren

    return 0;
}
