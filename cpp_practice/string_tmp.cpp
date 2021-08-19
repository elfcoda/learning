#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <cassert>
#include <string>
#include <type_traits>

using namespace std;

template <class T>
void f2(T&& s) { cout << "Rvalue" << endl; }

template <>
void f2<std::string&>(std::string& s) { cout << "aaa" << endl; }


int main()
{
    static_assert(std::is_same_v<>, "err");
    string s = "sasd";
    // f2(s);
    cout << s << endl;
    return 0;
}

