
class Solution{
public:
    void dfs(int node, vector<vector<int>>&adj, int &visitedCount, vector<bool>&visited){
        visited[node] = true;
        visitedCount++;
        for(auto edge : adj[node]){
            if(!visited[edge]){
                dfs(edge, adj, visitedCount, visited);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>&edges){
        if(edges.size() != n-1) return false;
        vector<vector<int>>adjacentList(n);
        // vector<vector<int>>adjacentList;
        for(auto item : edges){
            adjacentList[item[0]].push_back(item[1]);
            adjacentList[item[1]].push_back(item[0]);
        }

        vector<bool>visited(n, false);
        int visitedCount = 0;
        dfs(0, adjacentList, visitedCount, visited);
        // dfs(0, edges, visitedCount, visited);
        
        return visitedCount == n;
    }
};

