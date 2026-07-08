class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int>v1(26, 0);
        vector<int>v2(26, 0);

        for(auto item : s1){
            v1[item - 'a']++;
        }

        int right = 0;
        int left = 0;
        while(right < s2.size())
        {
            v2[s2[right] - 'a']++;

            if(v1 == v2)return true;
            if(right - left + 1 < s1.size()){
                right++;
            }else{
                v2[s2[left] - 'a']--;
                left++;
                right++;
            }
        }
        return false;
    }
};
