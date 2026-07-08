class Solution {
public:
    string minWindow(string s, string t) {

        vector<int>freq(128, 0);
        for(auto c :t)freq[c]++;

        int requried =  t.size();
        int start = 0;
        int minLen = INT_MAX;
        int left = 0;
        int right = 0;


        while(right < s.size())
        {
            if(freq[s[right]] > 0) requried--;
            freq[s[right]]--;
            right++;

            while(requried == 0)
            {
                if(right - left < minLen)
                {
                    minLen = right - left;
                    start = left;
                }

                freq[s[left]]++;
                if(freq[s[left]] > 0)requried++;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
