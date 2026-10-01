class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;
        for(int i = 0; i<32; i++){
            ret <<= 1;
            if(n&1){
                ret |= 1;
            }
            n/=2;
        }
        return ret;
    }
};
