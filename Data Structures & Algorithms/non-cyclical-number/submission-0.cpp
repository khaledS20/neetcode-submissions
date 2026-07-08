class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>holder;

        while(true){
            int val = 0;
            while(n){
                int d = n%10;
                val += d*d;
                n/=10;
            }
            if(holder.count(val))return false;
            if(val == 1)return true;
            holder.insert(val);
            n = val;
        }
    }
};
