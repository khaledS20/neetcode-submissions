class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>result;
        vector<int>prefix;
        vector<int>suffix;

        prefix.push_back(1);
        suffix.push_back(1);

        for(int i = 0; i<nums.size(); i++){
            prefix.push_back(prefix.back() * nums[i]);
        }

        for(int i = nums.size() - 1; i>= 0; i--){
            suffix.push_back(suffix.back() * nums[i]);
        }


        reverse(suffix.begin(), suffix.end());

        for(int i = 0; i<nums.size(); i++){
            result.push_back(1LL * prefix[i] * suffix[i + 1]);
        }

        return result;
    }
};
