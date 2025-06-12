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
    int res=INT_MIN;
    int solve(TreeNode* root){
        if(root==nullptr) return 0;  //base case
        int ls=solve(root->left);
        int rs=solve(root->right);    //hypothesis

        int temp=max(max(ls,rs)+root->val,root->val);  // passing to parent
        int ans=max(temp,ls+rs+root->val);   // considering the current ndoe as top of an arch
        res=max(res,ans);// storing maximum till now
        return temp;   

    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return res;
    }
};