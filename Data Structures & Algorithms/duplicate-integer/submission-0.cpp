class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int>frequancy;

        for(auto &num : nums){
            frequancy[num]++;
            if(frequancy[num] > 1) return true;
        }

        return false;
    }
};