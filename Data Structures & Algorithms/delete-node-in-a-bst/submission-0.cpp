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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(root->val == key){
            if(!root->left && !root->right)return nullptr;
            if(!root->left || !root->right){
                if(root->left)return root->left;
                else return root->right;
            }

            TreeNode* predesesor = root->left;
            while(predesesor->right){
                predesesor = predesesor->right;
            }
            root->val = predesesor->val;
            root->left = deleteNode(root->left, predesesor->val);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};