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
    void dfs(TreeNode*root, int level, vector<int>&ret){
        if(!root)return;

        if(ret.size() == level){
            ret.push_back(root->val);
        }
        dfs(root->right, level + 1, ret);
        dfs(root->left, level + 1, ret);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ret;
        dfs(root, 0, ret);
        return ret;
    }
};
