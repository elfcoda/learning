#include <iostream>
#include "in.h"
using namespace std;

class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (!root || !root->left) return root;
        TreeNode *l = root->left, *r = root->right;
        TreeNode *res = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};

int main()
{
    Solution* sol = new Solution();
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    printtree(root);
    TreeNode* ans = sol->upsideDownBinaryTree(root);
    printtree(ans);
    return 0;
}
