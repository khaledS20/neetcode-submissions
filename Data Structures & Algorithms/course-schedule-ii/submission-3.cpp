class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>degree(numCourses, 0);
        vector<int>result;

        for(auto &pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
            degree[pre[0]]++;
        }

        queue<int>process;

        for(int i =0; i<numCourses; i++){
            if(degree[i] == 0){
                process.push(i);
            }
        }

        int count = 0;
        while(!process.empty()){
            int top = process.front();
            process.pop();
            result.push_back(top);
            for(auto item : graph[top]){
                degree[item]--;
                if(degree[item] == 0){
                    process.push(item);
                }
            }
        }
        return result.size() != numCourses ? vector<int>{} : result;       
    }
};
