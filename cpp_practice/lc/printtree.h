#pragma once

#include "lib.h"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool vecHasVal(const vector<TreeNode*>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != nullptr) return true;
    }
    return false;
}



const static int singleWidth = 5;
int leftWidth(string s, int totalLen = singleWidth) {
    assert(s.length() < totalLen);
    return totalLen - s.length();
}

void fillNBlank(int n) {
    for (int i = 0; i < n; i++) cout << " ";
}

void printtree(TreeNode* root)
{
    if (root == nullptr) return;
    vector<TreeNode*> ve = {root};
    vector<vector<string>> output;
    while (vecHasVal(ve)) {
        vector<TreeNode*> tmp;
        vector<string> curVal;
        cout << endl;
        for (int i = 0; i < ve.size(); i++) {
            TreeNode* node = ve[i];
            if (node == nullptr) {
                curVal.push_back("#");
                tmp.push_back(nullptr);
                tmp.push_back(nullptr);
            } else {
                curVal.push_back(to_string(node->val));
                tmp.push_back(node->left);
                tmp.push_back(node->right);
            }
        }
        output.push_back(curVal);
        swap(ve, tmp);
    }

    // print output value
    int layer = output.size();
    int width = pow(2, layer - 1) * singleWidth;
    for (int i = 0; i < output.size(); i++) {
        int curLen = pow(2, i);
        int curSingle = width / curLen;
        for (int j = 0; j < output[i].size(); j++) {
            string s = output[i][j];
            fillNBlank(leftWidth(s, curSingle) / 2);
            cout << s;
            fillNBlank(curSingle - leftWidth(s, curSingle) / 2 - s.length());
        }
        cout << endl;
    }
}

