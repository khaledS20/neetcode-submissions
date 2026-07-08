class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        if(n < 0){
            x = 1/x;
        }
        while(n){
            if(n&1){
                result *= x;
            }
            x*=x;
            n/=2;
        }

        return result;
    }
};
