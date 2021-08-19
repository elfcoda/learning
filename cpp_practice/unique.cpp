#include <iostream>
#include "in.h"
using namespace std;

class A{};

class B: public A {};
class C: public A {};

std::unique_ptr<A> func()
{
    auto a = std::make_unique<B>();
    return a;
}

int main()
{
    std::unique_ptr<A> a = std::make_unique<A>();
    std::unique_ptr<B> b = std::make_unique<B>();

    b = func();
    return 0;
}
