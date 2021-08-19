#include <iostream>
#include "in.h"
using namespace std;

class cat
{
    public:
        cat() { cout << "do cat" << endl; }
        virtual void f()  = 0;  // {cout << "f cat" << endl;}

        // 只要进去了函数里面，不再有基类指针，那就只会执行本类的函数，不用管是不是虚函数，不会有其他问题!!!
        virtual ~cat() {cout << "undo cat" << endl; doit();}

        virtual void doit() { cout << "do it" << endl; }
};

class mcat: public cat
{
    public:
        mcat() { cout << "do mcat" << endl; }

        // 只要进去了函数里面，不再有基类指针，那就只会执行本类的函数，不用管是不是虚函数，不会有其他问题!!!
        void f() {cout << "f mcat" << endl; doit();}
        ~mcat() {cout << "undo mcat" << endl; doit(); }

        void doit() { cout << "do it child" << endl; }
};

// cat cat::b(7);

int main()
{
    cat* m = new mcat();
    // m->f();
    delete m;

    return 0;
}
