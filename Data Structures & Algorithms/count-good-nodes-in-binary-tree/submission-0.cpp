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
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, count, INT_MIN);
        return count;
    }
    void dfs(TreeNode *root, int &count, int maxVal){
        if(!root)return;

        if(root->val >= maxVal){
            count++;
            maxVal = root->val;
        }
        dfs(root->left, count, maxVal);
        dfs(root->right, count, maxVal);
    }
};
