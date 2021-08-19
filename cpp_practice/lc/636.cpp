#include <iostream>
#include "in.h"
#include <sstream>
using namespace std;
/*
 * n = 2
logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
 * */
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        using LogType = std::tuple<int, int, int>;
        std::stack<LogType> input;
        map<int, int> ma;
        for (const string& s: logs) {
            stringstream ss(s);
            string e;
            vector<string> tmp;
            while (std::getline(ss, e, ':')) {
                tmp.push_back(e);
            }

            if (!input.empty()) {
                LogType t = input.top();
                if (get<0>(t) == std::stoi(tmp[0])) {
                    input.pop();
                    ma[get<0>(t)] = std::stoi(tmp[2]) - get<2>(t) + 1 - get<1>(t);
                    if (!input.empty()) {
                        auto tt = input.top();
                        input.pop();
                        input.push(LogType(get<0>(tt), ma[get<0>(t)] + get<1>(t)  + get<1>(tt), get<2>(tt)));
                    }
                } else {
                    input.push(LogType(std::stoi(tmp[0]), 0, std::stoi(tmp[2])));
                }
            } else {
                input.push(LogType(std::stoi(tmp[0]), 0, std::stoi(tmp[2])));
            }
        }

        vector<int> ans;
        for (auto item: ma) {
            ans.push_back(item.second);
        }

        return ans;
    }
};
int main()
{
    Solution* sol = new Solution();
    vector<string> vec = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    sol->exclusiveTime(2, vec);
    return 0;
}
