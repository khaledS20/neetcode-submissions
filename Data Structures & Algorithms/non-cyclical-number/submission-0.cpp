class Solution {
public:
    bool isHappy(int n) {
        int result = 0;
        unordered_set<int>hold;
        while(true){
            while(n){

                int d = n%10;
                result += d*d;
                n/=10;
            }
            if(result == 1) return true;
            if(hold.find(result) != hold.end())return false;
            hold.insert(result);
            n = result;
            result = 0;
        }
        return false;
    }
};
