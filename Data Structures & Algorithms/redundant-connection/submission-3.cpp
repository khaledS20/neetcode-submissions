class Solution {
public:
    bool dfs(int node, int target, vector<bool>&v, vector<vector<int>>&adj){
        if (node == target){
            return true;
        }

        v[node] = true;
        for(auto& nei : adj[node]){
            if(!v[nei]){
                if(dfs(nei, target, v, adj)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adjList(n+1);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            vector<bool>visited(n+1, false);

            if(!adjList[u].empty() && !adjList[v].empty() && dfs(u, v, visited, adjList)){
                return e;
            }

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return {};
    }
};
