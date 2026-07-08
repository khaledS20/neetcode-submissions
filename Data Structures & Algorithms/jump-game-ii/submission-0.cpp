class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int right = 0;
        int left = 0;
        int size = nums.size() - 1;
        int farthest = 0;


        while(right < size){
            farthest = 0;
            for(int i = left; i<=right; i++){
                farthest = max(farthest, i+nums[i]);
            }

            left = right + 1;
            right = farthest;
            result++;
        }

        return result;
    }
};
