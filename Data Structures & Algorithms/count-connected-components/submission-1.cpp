// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
//         visited[node] = true;
//         for (int nei : graph[node]) {
//             if (!visited[nei]) {
//                 dfs(nei, graph, visited);
//             }
//         }
//     }

//     int countComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> graph(n);
//         for (auto& e : edges) {
//             graph[e[0]].push_back(e[1]);
//             graph[e[1]].push_back(e[0]);
//         }

//         vector<bool> visited(n, false);
//         int components = 0;

//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 dfs(i, graph, visited);
//                 components++;
//             }
//         }

//         return components;
//     }
// };





class Solution{
public:
void dfs(vector<vector<int>>&adjacentList, vector<bool>&visited, int node){
    visited[node] = true;
    for(auto nei : adjacentList[node]){
        if(!visited[nei]){
            dfs(adjacentList, visited, nei);
        }
    }
}
int countComponents(int n, vector<vector<int>>& edges){

    vector<vector<int>>adjacentList(n);
    for(auto &edge : edges){
        adjacentList[edge[0]].push_back(edge[1]);
        adjacentList[edge[1]].push_back(edge[0]);
    }

    vector<bool>visited(n, false);
    int components = 0;
    for(int i =0; i<n; i++){
        if(!visited[i]){
            dfs(adjacentList, visited, i);
            components++;
        }
    }

    return components;



}
};