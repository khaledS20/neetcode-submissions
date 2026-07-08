class Solution {
public:
    vector<string> result;         // Stores all combinations
    string path;                   // Current combination being built
    vector<string> mapping = {     // Phone keypad mapping
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void dfs(string &digits, int idx){
        if(idx == digits.size()){
            result.push_back(path);
            return;   
        }

        string letters = mapping[digits[idx] - '0'];
        for(auto c : letters){
            path.push_back(c);
            dfs(digits, idx+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        dfs(digits, 0);
        return result;
    }
};
