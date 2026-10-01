class Solution {
public:
    int bits(int i){
        int c = 0;
        while(i){
            if(i&1)c++;
            i/=2;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int>r(n + 1, 0);
        for(int i = 0; i<= n; i++){
            r[i] = bits(i);
        }
        return r;
    }
};
