class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() %groupSize != 0) return false;
        int ans = 0;

        unordered_map<int, int>freq;

        for(auto item : hand)freq[item]++;

        sort(hand.begin(), hand.end());

        for(auto it : hand){
            if(freq.count(it)){
                int size = groupSize;
                while(size--){
                    if(!freq.count(it))return false;
                    freq[it]--;
                    if(freq[it] == 0){
                        freq.erase(it);
                    }
                    it++;
                }
                ans++;
            }
        }
        return ans == hand.size() / groupSize;
    }
};
