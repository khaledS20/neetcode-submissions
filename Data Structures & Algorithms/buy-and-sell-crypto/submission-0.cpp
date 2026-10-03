class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int left = 0;
        for(int right = 0; right<prices.size(); right++){

            if(prices[left] > prices[right]){
                left = right;
            }
            maxProf = max(maxProf, prices[right] - prices[left]);
        }
        return maxProf;
    }
};
