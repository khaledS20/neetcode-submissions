class Solution {
public:
    vector<vector<int>>r;
    vector<int>p;
    void dfs(vector<int>&n, vector<bool>u){
        if(n.size() == p.size()){
            r.push_back(p);return;
        }
        for(int i =0; i<n.size(); i++){

            if(u[i]) continue;
            p.push_back(n[i]);
            u[i] = true;

            dfs(n, u);
            
            p.pop_back();
            u[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>u(nums.size(), false);
        dfs(nums, u);
        return r;
    }
};
