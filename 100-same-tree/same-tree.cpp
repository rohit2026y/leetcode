/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSame = true;

    void solve(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return; // base case: both null => same at this node

        if (p == nullptr || q == nullptr || p->val != q->val) {
            isSame = false;  // trees differ
            return;
        }

        solve(p->left, q->left);    // recursive check on left subtree
        solve(p->right, q->right);  // recursive check on right subtree
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        solve(p, q);
        return isSame;
    }
};
