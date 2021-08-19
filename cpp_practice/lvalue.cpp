#include "in.h"
using namespace std;

template <typename T>
constexpr bool is_vector = std::is_same_v<typename std::decay<T>::type, std::vector<typename std::decay<T>::type::value_type, typename std::decay<T>::type::allocator_type>>;

template <typename T>
struct is_container_vector_helper
{
    constexpr static bool is_vector = false;
};
template <typename... U>
struct is_container_vector_helper<std::vector<U...>>
{
    constexpr static bool is_vector = true;
};

template <typename T>
struct is_container_vector
{
    constexpr static bool is_vector = is_container_vector_helper<typename std::decay<T>::type>::is_vector;
};

class AA{
    public:
    int AA_a;
    AA(int i){ cout << "do" << endl; AA_a = 7;}
    AA(const AA& aa) { cout << "con &" << endl; AA_a = 8; }
    AA(const AA&& aa) { cout << "con &&" << endl;  AA_a = 9; }
    ~AA(){ cout << "undo" << endl;}
};


// 容器直接这样返回，并不会影响性能，类和结构体也是
// 编译器会延长生命周期，而不是重新构造析构
vector<AA> f1()
{
    vector<AA> v;
    // 直接在容器里面构造
    v.emplace_back(7);
    cout << "gafa" << endl;
    return v;
}

void f1(int&& x)
{
    cout << "rrrrr" << endl;
}

template <class T, class U>
std::enable_if_t<is_container_vector<T>::is_vector &&
                 is_container_vector<U>::is_vector &&
                 std::is_same_v<typename std::decay_t<T>::value_type,
                                typename std::decay<U>::type::value_type>,
                 void>
h1(T&& v1, U&& v2)
{
}



int main()
{
    // prolong lifetime of a
    // 也可以直接延长容器的生命周期
    vector<AA> bb = f1();
    cout << "" << " aaa" << endl;
    // std::vector<int> v1 = {1};
    // std::vector<int> v2 = {1};
    // h1(v1, std::vector<int>{1});
    return 0;
}
