#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <type_traits>
using namespace std;

template <class T>
constexpr bool is_vector = std::is_same_v<typename std::decay<T>::type, std::vector<typename T::value_type, typename T::allocator_type>>;

int main()
{
    if (is_vector<std::vector<unsigned>>) {
        cout << "is vector" << endl;
    } else {
        cout << "not vector" << endl;
    }
    return 0;
}
