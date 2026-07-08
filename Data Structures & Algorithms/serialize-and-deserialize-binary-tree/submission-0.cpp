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

class Codec {
public:

    // Encodes a tree to a single string.
    void dfsSerialize(TreeNode* root, string &ret)
    {
        if(!root){
            ret+="null,";
            return;
        }

        ret+=to_string(root->val) + ',';
        dfsSerialize(root->left, ret);
        dfsSerialize(root->right, ret);
    }
    string serialize(TreeNode* root) {
        string ret;
        dfsSerialize(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* dfsDeserialize(vector<string>&data, int&idx){
        if(data[idx] == "null"){
            idx++;
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(data[idx]));
        idx++;

        root->left = dfsDeserialize(data, idx);
        root->right = dfsDeserialize(data, idx);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string>tokens;
        string token;
        stringstream ss(data);
        while(getline(ss, token, ',')){
            tokens.push_back(token);
        }
        int idx = 0;
        return dfsDeserialize(tokens, idx);
    }
};
