class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string, vector<string>>hold;


        for(auto &str : strs){
            int freq[26] = {};
            for(int i = 0; i<str.size(); i++){
                freq[str[i] - 'a']++;
            }

            string key = "";

            for(int i = 0; i<26; i++){
                key += '#' + to_string(freq[i]);
            }

            hold[key].push_back(str);
        }

        for(auto &[first, second] : hold){
            result.push_back(second);
        }

        return result;
    }
};
