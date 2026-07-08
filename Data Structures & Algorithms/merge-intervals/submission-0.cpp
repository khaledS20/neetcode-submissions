class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>merged;
        sort(intervals.begin(), intervals.end());

        merged.push_back(intervals[0]);

        int n = intervals.size();

        for(int i =1; i<n; i++){
            if(merged.back()[1] >= intervals[i][0]){
                merged.back()[1]= max(intervals[i][1], merged.back()[1]);
            }else{
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
