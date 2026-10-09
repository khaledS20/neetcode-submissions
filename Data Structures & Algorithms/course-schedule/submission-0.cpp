class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
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


        int count = 0;

        while(!hold.empty()){
            auto item = hold.front();
            hold.pop();
            count++;

            for(auto element : adj[item]){
                degree[element]--;
                if(degree[element] == 0){
                    hold.push(element);
                }
            }
        }
        return n == count;
    }
};
