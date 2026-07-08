class Solution {
public:
    void dfs(vector<string>&result, string word, int n, int open, int close){
        if(close + open == 2*n){
            result.push_back(word);
            return;
        }

        if(open < n){
            dfs(result, word + '(', n, open + 1, close);
        }
        if(close < open){
            dfs(result, word + ')', n, open, close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        dfs(result, "", n, 0, 0);
        return result;
    }
};
