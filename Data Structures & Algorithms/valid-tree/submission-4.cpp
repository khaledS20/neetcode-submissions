class Solution {
public:
    void dfs(vector<bool>&v, vector<vector<int>>&adj, int &nodes, int node){
        v[node] = true;
        nodes++;
        for(auto &nei : adj[node]){
            if(!v[nei]){
                dfs(v, adj, nodes, nei);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        
        int s = edges.size();
        if(n-1 != s){
            return false;
        }

        vector<vector<int>>adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int nodes = 0;
        vector<bool>visited(n, false);
        dfs(visited, adj, nodes, 0);

        return n == nodes;
    }
};
