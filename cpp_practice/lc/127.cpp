#include <iostream>
#include "in.h"
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<string> qu = {beginWord};
        int len = beginWord.length();
        auto it = words.find(beginWord);
        if (it != words.end()) words.erase(it);
        int ladder = 0;
        while (!qu.empty()) {
            vector<string> newVec;
            for (int i = 0; i < qu.size(); i++) {
                string curStr = qu[i];
                if (curStr == endWord) return ladder;
                for (int j = 0; j < len; j++) {
                    string w = curStr;
                    for (int k = 0; k < 26; k++) {
                        w[j] = 'a' + k;
                        auto it2 = words.find(w);
                        if (it2 != words.end()) {
                            words.erase(it2);
                            newVec.push_back(w);
                        }
                    }
                }
            }
            swap(qu, newVec);
            ladder++;
        }
        return 0;
    }
};

int main()
{
    vector<string> v = {"hot","dot","dog","lot","log","cog"};
    Solution* sol = new Solution();
    cout << sol->ladderLength("hit", "cog", v);
    return 0;
}
