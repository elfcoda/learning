#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <cassert>
#include <string>
#include <type_traits>

using namespace std;

template <template<typename...> typename M,
          typename M1,
          typename M2,
          template<typename...> typename S>
void unionSet2Map(M<M1, M2>& fst, const S<M1>& snd, M2 m2)
{
    static_assert((std::is_same_v<M<M1, M2>, std::unordered_map<M1, M2>> || std::is_same_v<M<M1, M2>, std::map<M1, M2>>) &&
                  (std::is_same_v<S<M1>, std::unordered_set<M1>> || std::is_same_v<S<M1>, std::set<M1>>),
                  "M should be [unordered_]map type and S should be [unordered_]set type");
    for (const M1 e: snd) fst[e] = m2;
}

template <class T>
struct XXX{};

int main()
{
    map<unsigned, bool> fst;
    set<unsigned> snd;
    bool b;
    unionSet2Map<map, unsigned, bool, set>(fst, snd, b);
    return 0;
}
