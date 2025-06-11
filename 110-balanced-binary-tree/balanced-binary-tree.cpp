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
    int BTheight(TreeNode* root){
        if(root==nullptr) return 0;
        int lh=BTheight(root->left);
        int rh=BTheight(root->right);
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;

        int lh=BTheight(root->left);
        int rh=BTheight(root->right);
        if(abs(lh-rh)>1) return false;

        bool b1=isBalanced(root->left);
        bool b2=isBalanced(root->right);
        return b1&&b2;
    }
};