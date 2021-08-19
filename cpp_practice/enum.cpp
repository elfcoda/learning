#include <iostream>
using namespace std;

enum XX
{
    A = 1,
    B = 0,
    C,
};

int main()
{
    if (B < A) cout << "aaa" << endl;
    else cout << "bbb" << endl;
    return 0;
}
