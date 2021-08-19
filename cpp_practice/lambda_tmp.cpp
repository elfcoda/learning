#include <set>
#include <unordered_set>
#include <iostream>
#include <cassert>
#include <string>
#include <type_traits>
// #include "/Users/luwenjie/git/jhin/jhin/src/syntax/../../comm/container_op.h"

using namespace std;

    template <typename S,
              typename T = unsigned>
    void unionSet2Set(S& fst, const S& snd)
    {
        static_assert(std::is_same_v<S, std::unordered_set<T>> || std::is_same_v<S, std::set<T>>, "S should be [unordered_]set type");
        for (T e: snd) fst.insert(e);
    }

int main()
{
    // func<int>(f2, 2);               // OK, 普通函数可以
    // func<int>([](int a) {}, 2);     // BAD, 匿名函数不行，但是把<class... T1>变成<class T1>后可以
    // func<int>(+[](int a) {}, 2);    // OK, 加上加号可以编译
    set<unsigned> fst;
    set<unsigned> snd;

    unionSet2Set<set<unsigned>>(fst, snd);
    return 0;
}
