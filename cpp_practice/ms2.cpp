#include <iostream>
#include "in.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* l, TreeNode* r): val(val), left(l), right(r) {}
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

TreeNode* solve(TreeNode* root, int n1, int n2) {
    if (root == nullptr) return root;
    if (root->val == n1 || root->val == n2) return root;
    TreeNode* left = solve(root->left, n1, n2);
    TreeNode* right = solve(root->right, n1, n2);
    if (left == nullptr && right == nullptr) return nullptr;
    else if (left == nullptr && right) return right;
    else if (right == nullptr && left) return left;
    return root;
}

int main()
{
    TreeNode* root = nullptr;
    root = new TreeNode(1,
           new TreeNode(2, nullptr, nullptr),
           new TreeNode(3, nullptr, nullptr));

    root = nullptr;

    root = new TreeNode(1,
                        new TreeNode(2,
                                     new TreeNode(3),
                                     new TreeNode(4,
                                         new TreeNode(5),
                                         new TreeNode(6))),
                        new TreeNode(7, nullptr, new TreeNode(8)));

    TreeNode* ans = solve(root, 6, 8);

    if (ans) cout << ans->val;
    else cout << "ans is nullptr" << endl;

    return 0;
}


