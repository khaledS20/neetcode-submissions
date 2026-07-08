class Solution {
public:
    void dfs(int node, vector<bool>&visited, int &countNodes, vector<vector<int>>&adjList){
        visited[node] = true;
        countNodes++;
        for(auto edge : adjList[node]){
            if(!visited[edge]){
                dfs(edge, visited, countNodes, adjList);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n - 1 != edges.size()){
            return false;
        }

        vector<vector<int>>adjList(n);

        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int countNodes = 0;
        vector<bool>visited(n, false);
        dfs(0, visited, countNodes, adjList);

        return n == countNodes;
    }
};
