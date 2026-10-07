class Solution {
public:
    bool solve(int speed, vector<int>&piles, int h){
        int hours = 0;

        for(auto pile : piles){
            hours += ceil((double)pile/speed);
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if(solve(mid, piles, h)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
