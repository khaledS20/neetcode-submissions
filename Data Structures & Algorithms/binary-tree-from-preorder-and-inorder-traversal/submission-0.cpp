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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx)
    {
        if(start>end)return nullptr;
        int subRootVal = preorder[idx];
        idx++;
        int i = start;
        while(i<end){
            if(inorder[i] == subRootVal)break;
            i++;
        }

        TreeNode* node = new TreeNode(subRootVal);
        node->left = dfs(preorder, inorder, start, i - 1, idx);
        node->right = dfs(preorder, inorder, i + 1, end, idx);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;
        return dfs(preorder, inorder, 0, n-1, idx);
    }
};
