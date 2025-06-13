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
    int maxi=INT_MIN;
    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        int lh=solve(root->left);
        if(lh<0) lh=0;
        int rh=solve(root->right);
        if(rh<0) rh=0;

        maxi=max(maxi,lh+rh+root->val);
        return max(lh,rh)+root->val;

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};