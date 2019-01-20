#include <vector>
#include <set>
#include <iostream>

using std::vector, std::set, std::cout;
using vector_t = vector<unsigned long long>; // Ihr eigener Typalias

int main()
{
    vector_t huge { 12ULL, 10'000'000'000ULL, 9ULL, 0ULL, };
    vector_t::size_type sz = huge.size();
    vector_t::value_type uiuiui = huge[1];
    for (vector_t::iterator it = huge.begin(); it != huge.end(); ++it)
    {
        *it *= 2; // verdoppeln
    }
    /* sortieren per set */
    set<vector_t::value_type> sortiert { huge.begin(), huge.end() };
    for (vector_t::value_type val : sortiert)
    {
        cout << val << " ";
    }
    cout << "\n";
}