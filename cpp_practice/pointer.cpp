#include <memory>
#include <iostream>
using namespace std;

class B;

class A{
    public:
        int a1;
        std::shared_ptr<B> pB;
        A(int a)
        {
            a1 = a;
        }
};

class B{
    public:
        int b1;
        std::shared_ptr<A> pA;
};

std::weak_ptr<A> gw;

int main()
{
    std::shared_ptr<A> sp = nullptr;
    {
        sp = std::make_shared<A>(7);
        auto sp2 = sp;
        auto sp3 = sp;
        gw = sp;
        std::cout << gw.use_count() << std::endl;
        cout << sp->a1 << endl;
        cout << sp2->a1 << endl;
        cout << sp3->a1 << endl;
    }
    // std::cout << gw.use_count() << std::endl;
    return 0;
}
