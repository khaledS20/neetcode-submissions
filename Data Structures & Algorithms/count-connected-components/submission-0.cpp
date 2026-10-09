class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>&v,  int n){
        v[n] = true;

        for(auto nei : adj[n]){
            if(!v[nei]){

                dfs(adj, v,  nei);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n, false);


        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int c = 0;

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                c++;
                dfs(adj, visited,  i);
            }
        }

        return c;
    }
};
