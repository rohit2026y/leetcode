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

    int Height(TreeNode* root){
        if(root==nullptr) return 0;
        int lh=Height(root->left);
        int rh=Height(root->right);
        return 1+max(lh,rh);
    }
    int maxi=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=Height(root->left);
        int rh=Height(root->right);
        maxi=max(maxi,lh+rh);
        diameterOfBinaryTree(root->left);
        
        diameterOfBinaryTree(root->right);
        return maxi;
    }
};

// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
        
//     }
// };