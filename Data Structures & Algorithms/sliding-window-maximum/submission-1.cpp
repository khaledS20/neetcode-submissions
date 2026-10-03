class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;

        priority_queue<pair<int, int>>maxHeap;
        for(int i = 0; i<nums.size(); i++){
            maxHeap.push({nums[i], i});
            if(i>= k -1){
                while(maxHeap.top().second <= i- k){
                    maxHeap.pop();
                }
                result.push_back(maxHeap.top().first);
            }
        }
        return result;
    }
};
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int>result;

//         for(int i = 0; i<= nums.size() - k; i++){
//             int mx = nums[i];

//             for(int j = i; j<i + k; j++){
//                 mx = max(mx, nums[j]);
//             }
//             result.push_back(mx);
//         }
//         return result;
//     }
// };
