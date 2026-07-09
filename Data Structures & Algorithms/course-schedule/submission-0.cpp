class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);
        vector<int>degree(n, 0);

        for(auto &e : edges){
            adjList[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }

        queue<int>q;

        for(int i = 0; i<n; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }

        int c = 0;
        while(!q.empty()){
            int t = q.front();q.pop();
            c++;
            for(auto &course : adjList[t]){
                degree[course]--;
                if(degree[course] == 0){
                    q.push(course);
                }
            }
        }
        return n == c;
    }
};
