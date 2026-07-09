class Solution {
public:
    void dfs(vector<bool>&v, vector<vector<int>>&a, int node){
        v[node] = true;

        for(auto& n : a[node]){
            if(!v[n]){
                dfs(v, a, n);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>>a(n);

        for(auto &e : edges){
            a[e[0]].push_back(e[1]);
            a[e[1]].push_back(e[0]);
        }

        int c= 0;
        vector<bool>v(n, false);

        for(int i = 0; i<n; i++){
            if(!v[i]){
                dfs(v, a, i);
                c++;
            }
        }
        return c;
    }
};
