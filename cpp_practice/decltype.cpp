#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct A{};
using pA = A*;

struct B: A{};
using pB = B*;

int main()
{
    pA n = nullptr;
    pA aa = new A();
    pB nb = nullptr;
    pB bb = new B();
    vector<pA> v = {bb};
    auto t = v[0];
    decltype(t) m = new A();
    return 0;
}
