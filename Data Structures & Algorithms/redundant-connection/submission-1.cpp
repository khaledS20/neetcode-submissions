class Solution {
private:
    vector<vector<int>>adjacentList;
public:
    bool dfs(int curr, int target, vector<bool>&visited){
        if(curr == target)return true;
        visited[curr] = true;

        for(auto &nei : adjacentList[curr]){
            if(!visited[nei]){
                if(dfs(nei, target, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        adjacentList.resize(n+1,vector<int>());

        for(auto &edge :edges){
            vector<bool>visited(n+1, false);

            if(!adjacentList[edge[0]].empty() && dfs(edge[0], edge[1], visited)){
                return edge;
            }

            adjacentList[edge[0]].push_back(edge[1]);
            adjacentList[edge[1]].push_back(edge[0]);
        }
        return {};
    }
};
