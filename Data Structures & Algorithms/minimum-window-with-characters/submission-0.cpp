class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128, 0);

        for(auto ch : t){
            freq[ch]++;
        }

        int left = 0;
        int right = 0;
        int start = 0;
        int minLen = INT_MAX;
        int require = t.size();

        while(right < s.size()){
            if(freq[s[right]] > 0)require--;
            freq[s[right]]--;
            right++;

            while(require == 0){
                if(right - left < minLen){
                    minLen = right - left;
                    start = left;
                }

                freq[s[left]]++;
                if(freq[s[left]] > 0)require++;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
