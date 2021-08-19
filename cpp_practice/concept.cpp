#include <iostream>
#include <set>
#include <concepts>
using namespace std;

template<typename T>
concept Integral = std::is_integral<T>::value;

int main()
{
    return 0;
}
