class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>h;

        for(auto n : nums){
            h.push(n);
        }

        for(int i = 0; i<k-1 &&!h.empty(); i++){
            h.pop();
        }

        return h.top();
    }
};
