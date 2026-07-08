class Solution {
public:
    int reverse(int x) {
        long long y = 0;
        while(x){
            int dig = x%10;
            y = y*10+dig;
            x/=10;
        }
        if(y > INT_MAX)return 0;
        if(y < INT_MIN)return 0;
        return y ;
    }
};
