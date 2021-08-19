#include <iostream>
#include "in.h"
using namespace std;
/*
 *
2,3
1,2,3,5
1,3,4,6,7,8
1 3 4 6 7 8 0 0
1 0 1 1 0 1 1 1
1,2,3,4,5,6,8   lo = 0, hi = 6  mid = 3
 * */   lo  lo hi  7

int solve(vector<int>& vec) {
    int len = vec.size(), maxVal = vec[len - 1];
    if (len == 0) return 1;
    int lo = 0, hi = len - 1;   // 1 3 4 5 6 7 8  lo 0    hi 6
    while (lo != hi) {
        int mid = (lo + hi) / 2;   // mid : 1
        if (vec[mid] == mid + 1) lo = mid + 1;   //
        else hi = mid - 1;     // lo 0    hi 0
    }
    if (vec[lo] == lo + 1) { return vec[lo] + 1;}
    return -1;
}

int main()
{

    return 0;
}


