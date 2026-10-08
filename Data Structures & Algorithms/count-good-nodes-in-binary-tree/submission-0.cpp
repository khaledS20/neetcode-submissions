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
    void dfs(TreeNode*root, int maxVal, int &ret){
        if(!root)return;

        if(root->val >= maxVal){
            ret++;
            maxVal = root->val;
        }
        dfs(root->left, maxVal, ret);
        dfs(root->right, maxVal, ret);
    }
    int goodNodes(TreeNode* root) {
        int ret = 0;
        dfs(root, INT_MIN, ret);
        return ret;
    }
};
