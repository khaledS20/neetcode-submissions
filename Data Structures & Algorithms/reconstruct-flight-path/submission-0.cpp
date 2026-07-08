class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>>adj;
    vector<string>route;
public:
    void dfs(const string &airport){
        auto &dests = adj[airport];
        while(!dests.empty()){
            string next = dests.top();
            dests.pop();
            dfs(next);
        }
        route.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket : tickets){
            adj[ticket[0]].push(ticket[1]);
        }   
        dfs("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
};
