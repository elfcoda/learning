#include <iostream>
#include "in.h"
using namespace std;

class A{
    public:
        virtual void codegen() = 0;
};

class B: public A {
    public:
        virtual void codegen()  = 0;
};
class C: public B {
    public:
        void codegen()
        {
            cout << "aa" << endl;
        }
};


int main()
{
    A *c = new C();
    c->codegen();
    return 0;
}
