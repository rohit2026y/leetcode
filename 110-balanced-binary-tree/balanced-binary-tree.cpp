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
    int maxH(TreeNode* root){
        if(root==nullptr) return 0;
        int lh=maxH(root->left);
        int rh=maxH(root->right);
        if(abs(rh-lh)>1) return -1;
        if(rh==-1 || lh==-1) return -1;
        return 1+max(rh,lh);
    }
    bool isBalanced(TreeNode* root) {
        int check=maxH(root);
        if(check==-1) return false;
        return true;
    }
};