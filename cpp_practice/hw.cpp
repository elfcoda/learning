#include <iostream>
#include "in.h"
using namespace std;

bool isSubstr(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    // 要注意这里判断的是长度而不是字符串啊啊啊
    if (len1 < len2) return false;
    for (int i = 0; i <= len1 - len2; i++) {
        string sub = s1.substr(i, len2);
        if (sub == s2) return true;
    }
    return false;
}

string cutStr(string s, int idx) {
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        if (i != idx) ans.push_back(s[i]);
    }
    return ans;
}

// iioiooooiiooi
int solve(string s, string p) {
    int lenS = s.length(), lenP = p.length();
    if (lenS < lenP) return INT_MAX ;
    if (lenS == lenP) {
        if (s == p) return 0;
        return INT_MAX ;
    }
    if (isSubstr(s, p)) return 0;
    int subMin = INT_MAX ;
    for (int i = 0; i < lenS; i++) {
        string tmp = cutStr(s, i);
        int cnt = solve(tmp, p);
        if (cnt != INT_MAX) subMin = min(subMin, cnt);
        // if (tmp.length() == 5)
        // cout << cnt << " ";
    }
    if (subMin == INT_MAX) return INT_MAX;
    return subMin + 1;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
        cout << solve(s1, s2) << endl;
    return 0;
}

