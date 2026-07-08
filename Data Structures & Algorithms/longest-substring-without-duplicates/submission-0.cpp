class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>holder;
        int n = s.size();
        int left = 0;
        int maxLenght = 0;
        for(int right =0; right<n; right++)
        {
            while(holder.count(s[right])){
                holder.erase(s[left]);
                left++;
            }
            holder.insert(s[right]);
            maxLenght = max(maxLenght, right - left + 1);
        }
        return maxLenght;
    }
};
