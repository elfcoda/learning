#include <iostream>
#include "in.h"
using namespace std;

struct A
{
    A(int j) {}
    int i;
};

void func(const A& a)
{
    // a.i = 7;
    // int i = a.i;
}

int main()
{

    func(A(7));
    return 0;
}
