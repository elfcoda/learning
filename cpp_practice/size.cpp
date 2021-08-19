#include <iostream>
#include "in.h"
using namespace std;

int main()
{
    unsigned i;
    cout << sizeof(decltype(i)) << endl;
    return 0;
}
