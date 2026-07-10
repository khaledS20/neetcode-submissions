class Solution {
public:
    bool can(vector<int>&piles, int speed, int hours){
        int h = 0;
        for(auto pile : piles){
            h += ceil((double) pile/speed);
        }
        return h <= hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;

            if(can(piles, mid, h)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
