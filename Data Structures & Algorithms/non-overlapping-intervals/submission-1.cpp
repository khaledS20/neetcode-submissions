class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1] < b[1];
        });

        int count = 0;

        int over = intervals[0][1];

        for(int i = 1; i<intervals.size(); i++){
            if(over > intervals[i][0]){
                count++;
            }else{
                over = intervals[i][1];
            }
        }

        return count;
    }
};
