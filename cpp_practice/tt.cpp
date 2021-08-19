// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include "in.h"
using namespace std;

class A
{
    public:
    A(int i){}
    private:
    ~A(){}
};

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b(a.begin(), a.begin() + 3);
    for (auto i: b) {
        cout << i << " ";
    }
    return 0;
}
