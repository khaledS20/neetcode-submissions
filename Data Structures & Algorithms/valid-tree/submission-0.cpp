class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<bool>&visited, int &c, int n){
        visited[n] = true;
        c++;
        for(auto nei: adj[n]){
            if(!visited[nei]){
                dfs(adj, visited, c, nei);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n -1)return false;
        vector<vector<int>>adj(n);
        vector<bool>visited(n, false);
        int count = 0;

        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(adj, visited, count, 0);

        return n == count;
    }
};
