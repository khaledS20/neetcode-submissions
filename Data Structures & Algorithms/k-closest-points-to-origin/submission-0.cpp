class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>holder;

        for(auto point : points){
            int distance = point[0]*point[0] + point[1]*point[1];
            holder.push({distance, point});
            if(holder.size()>k)holder.pop();
        }

        vector<vector<int>>result;
        while(!holder.empty()){
            result.push_back(holder.top().second);
            holder.pop();
        }

        return result;
    }
};
