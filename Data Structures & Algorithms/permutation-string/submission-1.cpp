class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);
        int left = 0;

        for(int i = 0; i<s1.size(); i++){
            freq1[s1[i] - 'a']++;
        }

        for(int i = 0; i<s2.size(); ){
            freq2[s2[i] - 'a']++;
            if(freq1 == freq2) return true;
            if(i - left + 1 < s1.size()){
                i++;
            }else{
                freq2[s2[left] - 'a']--;
                i++;
                left++;
            }
        }

        return false;
    }
};
