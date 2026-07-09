class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left = 0;
        int length = 0;
        unordered_set<char>container;

        for(int right = 0; right<s.size(); right++){
            while(container.count(s[right])){
                container.erase(s[left]);
                left++;
            }
            container.insert(s[right]);
            length = max(length, right - left + 1);
        }
        return length;
    }
};
