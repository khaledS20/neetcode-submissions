class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int, int>>maxHeap;
        unordered_map<int, int>freq;
        vector<int>result;

        for(auto &num : nums){
            freq[num]++;
        }

        for(auto &[a, b] : freq){
            maxHeap.push({b, a});
        }


        for(int i = 0; (i<k && !maxHeap.empty()) ; i++){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
