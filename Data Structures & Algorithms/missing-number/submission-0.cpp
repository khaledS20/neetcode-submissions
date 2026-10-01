class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();

        long long s1 = ((n + 1) * n) / 2;
        long long s2 = accumulate(nums.begin(), nums.end(), 0);

        return s1 - s2;
    }
};
