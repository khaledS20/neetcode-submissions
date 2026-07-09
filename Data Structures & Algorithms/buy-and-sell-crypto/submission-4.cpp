class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int left = 0;
        int maxProf = 0;
        int minPrice = INT_MAX;

        for(int right = 0; right<prices.size(); right++){
           minPrice = min(minPrice, prices[right]);
           maxProf = max(maxProf, prices[right] - minPrice);
        }
    return maxProf;
    }
};
