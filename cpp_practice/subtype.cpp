#include <iostream>
#include "in.h"
using namespace std;

class Base{
    public:
        virtual bool getIsOne() { return false; }
        int a;
        Base() {}
        virtual ~Base() = default;
        virtual void go() = 0;
};

class Derived1: public Base {
    public:
        bool getIsOne() override { return true; }
        int b;
        Derived1() {}
        void go() override { cout << "go 1" << endl; }
        ~ Derived1() { cout << "del 1" << endl; }
};

class Derived2: public Base {
    public:
        int c;
        Derived2() {}
        void go() override { cout << "go 2" << endl; }
        ~ Derived2() { cout << "del 2" << endl; }
};

Base* func1() { return new Derived1(); }
Base* func2() { return new Derived2(); }

std::unique_ptr<Base> func3()
{
    return std::make_unique<Derived1>();
}

template <typename T>
std::unique_ptr<T> func4(std::unique_ptr<Base> base)
{
    T* x = dynamic_cast<T *>(base.get());
    std::unique_ptr<T> derivedPtr;
    if (x != nullptr) {
        base.release();
        derivedPtr.reset(x);
    }
    return derivedPtr;
}

int main()
{
    auto m = func1();
    cout << m->getIsOne() << endl;

    auto m1 = dynamic_cast<Derived1*>(func1()); // can not be 2
    auto m2 = dynamic_cast<Derived2*>(func2());

    // std::unique_ptr<Derived1> mm = dynamic_cast<std::unique_ptr<Derived1>>(func3());

    std::unique_ptr<Derived1> xxx = func4<Derived1>(func3());

    return 0;
}

