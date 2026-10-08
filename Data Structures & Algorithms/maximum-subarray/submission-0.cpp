class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int sum = 0;
        int left = 0;

        for(auto num : nums){
            sum += num;
            result = max(result, sum - left);
            left = min(left, sum);
        }
        return result;

    }
};
