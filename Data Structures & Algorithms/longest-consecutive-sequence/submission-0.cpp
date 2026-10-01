class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;

        unordered_set<int>hold(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(hold.find(nums[i] - 1) == hold.end()){
                int len = 1;
                while(hold.find(nums[i] + 1) != hold.end()){
                    len++;
                    nums[i] = nums[i] + 1;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
