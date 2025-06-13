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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;

        queue<TreeNode*> queueNode;
        queueNode.push(root);
        bool LeftToRight=true;
        while(!queueNode.empty()){
            int size=queueNode.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=queueNode.front();
                queueNode.pop();
                int index;
                if(LeftToRight) index=i;
                else index=size-1-i;
                row[index]=node->val;
                if(node->left) queueNode.push(node->left);
                if(node->right) queueNode.push(node->right);
            }
            LeftToRight=!LeftToRight;
            res.push_back(row);
        }
        return res;
    }
};