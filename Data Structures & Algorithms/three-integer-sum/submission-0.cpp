class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        int n = nums.size();

        for(int i =0; i<n; i++)
        {
            while(i && nums[i] == nums[i-1])i++;

            int j = i+1;
            int k = n-1;

            while(j<k)
            {
                int target = nums[i] + nums[j] + nums[k];
                if(target > 0)k--;
                else if(target < 0)j++;
                else{
                    result.push_back({nums[i] , nums[j] , nums[k]});
                    j++;
                    while(j<k && nums[j] == nums[j-1])j++;
                }
            }
        }
        return result;
    }
};
