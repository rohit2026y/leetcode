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
    bool issymm(TreeNode* p,TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;
        if(p->val!=q->val) return false;
        return issymm(p->left,q->right) && issymm(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        TreeNode* p=root->left;
        TreeNode* q=root->right;
        return issymm(p,q);
    }
};