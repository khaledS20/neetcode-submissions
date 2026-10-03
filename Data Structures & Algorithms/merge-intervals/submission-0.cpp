class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[0] < b[0];
        });
        vector<vector<int>>result;

        int n = intervals.size();
        result.push_back(intervals[0]);

        for(int i = 1; i<n; i++){
            if(result.back()[1] >= intervals[i][0]){
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }else{
                result.push_back(intervals[i]);
            }
        }

        return result;


    }
};
