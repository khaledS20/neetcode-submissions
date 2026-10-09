class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>degree(n, 0);
        queue<int>hold;

        for(auto p : pre){
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }

        for(int i = 0; i<n; i++){
            if(degree[i] == 0){
                hold.push(i);
            }
        }


        vector<int>result;

        while(!hold.empty()){
            auto item = hold.front();
            hold.pop();
            result.push_back(item);

            for(auto element : adj[item]){
                degree[element]--;
                if(degree[element] == 0){
                    hold.push(element);
                }
            }
        }
        if(result.size() != n)return {};
        return result;
    }
};
