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
    int dfs(TreeNode *root, int &ret)
    {
        if(!root)return 0;
        int l = max(0, dfs(root->left, ret));
        int r = max(0, dfs(root->right, ret));

        ret = max(ret, l+r+root->val);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        dfs(root, ret);
        return ret;
    }
};
