class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, greater<pair<vector<int>, int>>>heap;
        priority_queue<
                        pair<int, vector<int>>,
                        vector<pair<int, vector<int>>>,
                        greater<pair<int, vector<int>>>
        >heap;
        vector<vector<int>>result;
        for(auto p : points){
            int m = p[0] * p[0] + p[1] * p[1];
            heap.push({m, p});
        }

        for(int i = 0; i<k &&!heap.empty(); i++){
            result.push_back(heap.top().second);
            heap.pop();
        }

        return result;
    }
};