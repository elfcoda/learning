#include <iostream>
#include "in.h"
using namespace std;

class Solution {
public:
    bool isLower(char c) {
        return c >= 'a' && c <= 'z';
    }

    bool isPalindrome(string s) {
        printf("%d\n", '0');
        cout << toupper('0') << endl;
        return true;
    }
};

int main()
{
    Solution* sol = new Solution();
    sol->isPalindrome("race a car");
    return 0;
}
