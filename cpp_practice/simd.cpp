#include <iostream>
#include "in.h"
using namespace std;

union Uni
{
    int x;
    float y;
};

int main()
{
    Uni m;
    m.y = 1.2;
    cout << m.x << endl;
    cout << ULLONG_MAX << endl;
    long long n = 4608083138725491507;
    cout << n << endl;
    return 0;
}

