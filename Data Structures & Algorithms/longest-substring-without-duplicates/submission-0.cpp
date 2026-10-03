class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>hold;
        int maxLen = 0;
        int left = 0;

        for(int right = 0; right<s.size(); right++){
            while(hold.find(s[right]) != hold.end()){
                hold.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            hold.insert(s[right]);
        }
        return maxLen;
    }
};
