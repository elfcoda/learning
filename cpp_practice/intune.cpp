#include <iostream>
#include "in.h"
using namespace std;

/*
 *                                 ik
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * */

int solve(const vector<int>& nums, int s) {
    int i = 0, j = 0;
    int minVal = INT_MAX;
    long curVal = 0;
    for (int k = 0; k < nums.size(); k++) {
        if (nums[k] >= s) return 1;
        curVal += nums[k];
        // s = 21000217943
        if (curVal < s) { continue; }
        else {
            minVal = min(minVal, k - i + 1);
            while (curVal >= s) {
                curVal -= nums[i];
                i ++;
                if (curVal >= s) {
                    minVal = min(minVal, k - i + 1);
                }
            }
        }
    }

    return minVal == INT_MAX ? 0 : minVal;
}

int main()
{
    // vector<int> v = {1, 1, 1, 2, 1};
    // vector<int> v = {1, 1, 7, 2, 1};
    // vector<int> v = {1, 1, 7, 22, 1};
    // vector<int> v = {1, 100, 3, 22, 1};
    // vector<int> v = {1, 3, 3, 10, 1, 1};

    // vector<int> v = {};
    vector<int> v = {};
    cout << solve(v, 12) << endl;
    return 0;
}


