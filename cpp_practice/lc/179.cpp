#include <iostream>
#include "in.h"
using namespace std;

struct LN
{
    string val;
    LN(string _val): val(_val) {}

    friend bool operator <(LN l1, LN l2) {
        // cout << (l1.val + l2.val) << (l2.val + l1.val) << endl;
        return (l1.val + l2.val) < (l2.val + l1.val);
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        priority_queue<LN> qu;
        for (int num: nums) {
            qu.push(LN(to_string(num)));
        }
        string s;
        while (!qu.empty()) {
            LN node = qu.top();
            s += node.val;
            qu.pop();
        }
        return s;
    }
};

int main()
{
    vector<int> nums = {3, 30};
    Solution* sol = new Solution();
    cout << sol->largestNumber(nums);

    // for (int i: nums) cout << i << " ";
    return 0;
}
