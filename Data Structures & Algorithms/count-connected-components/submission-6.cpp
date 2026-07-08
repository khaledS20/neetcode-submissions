class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<bool>&v, int node){
        v[node] = true;

        for(auto &edge : adj[node]){
            if(!v[edge]){
                dfs(adj, v, edge);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);
        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }


        int componant = 0;
        vector<bool>visited(n, false);

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(adjList, visited, i);
                componant++;
            }
        }

        return componant;
    }
};
