class Solution {
public:

    bool can(vector<int>&piles, int speed, int h){
        int hours = 0;
        for(auto pile : piles){
            hours += ceil((double)pile/speed);
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;

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
