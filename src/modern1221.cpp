#include <iostream>

class Rect
{
    private:
        int area_;              // private Daten

    public:
        int x_, y_;
        void set(int x, int y) { x_=x; y_=y; area_=x_*y_ }
        int calc() { return area_; }
        Rect() = default;       // den Compilter einen Konstruktor generieren lassen
};

class Pow
{
    private:
        int result_;            // private Daten hält 'base' hoch 'exp'

    public:
        int base_, exp_;
        void set(int b, int e) {  /* ... */}
        int calc() { return result_; }
        Pow() : result_{1} {}   // base_, exp_ wurden 0, dann muss result_=1 werden
}
