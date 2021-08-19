#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <cassert>
#include <string>
#include <type_traits>
#include "/Users/luwenjie/git/jhin/jhin/src/syntax/../../comm/log.h"

using namespace std;
using namespace jhin::comm;



// template <>
// int f<const string>(const string t) { return 2; }
//
// template <>
// int f<string&&>(string&& t) { return 8; }
//
// template <>
// int f<string>(string t) { t = "aaa"; return 15; }

//template <class T>  int f(T&& t) { f2(forward<T>(t)); return 1; }
// template <>         int f<int>(int&& t) { return 3; }
// template <>         int f<int&>(int& t) { return 5; }
// template <>         int f<int&&>(int&& t) { return 7; }

//template <class T>  int f1(T& t) { f2(forward<T>(t));  return 11; }
// template <>         int f1<int>(int& t) { return 13; }
// template <>         int f1<int&>(int& t) { return 15; }
// template <>         int f1<int&&>(int& t) { return 17; }



template <class T>
void f2(T&& s) { cout << "Rvalue" << endl; }

template <class T>
void f2(T& s) { cout << "Lvalue " << endl; }

int main()
{
    Log log("test.log");
    log.init();
    string s = "dsa";
    // log >> "fsdgfsa";
    // log.write("asd");
    int i = 7;

    f2<int&>(i);
    // f<int>(7);
    // f<int&>(i);
    // f<int&&>(7);
    // f1<int>(i);
    // f1<int&>(i);
    // f1<int&&>(i);


    cout << "i: " << i << endl;
    return 0;
}

