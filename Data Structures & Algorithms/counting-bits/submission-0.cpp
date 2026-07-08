class Solution {
public:
    int ones(int n){
        int cnt = 0;
        for(int i =0; i<32; i++){
            if(n&1)cnt++;
            n>>=1;
        }return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>result(n+1, 0);
        for(int i =0;i<=n;i++){
            result[i] = ones(i);
        }return result;
    }
};
