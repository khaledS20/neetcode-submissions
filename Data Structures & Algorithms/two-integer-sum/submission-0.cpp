class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hold;


        for(int i = 0; i<nums.size(); i++){

            if(hold.find(target - nums[i]) != hold.end()){
                return {hold[target - nums[i]], i};
            }
            hold[nums[i]] = i;
        }

        return {-1, -1};
    }
};



/*




*/
