#include <iostream>
#include "in.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }

    int solve(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;
        int left = max(solve(root->left, ans), 0);
        int right = max(solve(root->right, ans), 0);
        ans = max(ans, left + right + root->val);
        return root->val + max(left, right);
    }
};

int main()
{
    TreeNode* root = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    // oot = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    // oot = new TreeNode(9);
    Solution* sol = new Solution();
    cout << sol->maxPathSum(root);
    return 0;
}
