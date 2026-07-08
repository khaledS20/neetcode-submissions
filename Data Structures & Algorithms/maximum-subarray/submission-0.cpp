class Solution {
public:
    int maxSubArray(vector<int>& nums) {

            int maxSub = INT_MIN;
            int minLeft  = 0;
            int sum = 0;
            for(auto &item : nums){
                sum+=item;
                maxSub = max(maxSub, sum - minLeft);
                minLeft = min(minLeft, sum);
            }
            return maxSub;
    }
};
