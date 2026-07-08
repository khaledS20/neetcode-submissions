class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int idx, int r, int c){
        if(idx == word.size()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if(board[r][c] != word[idx]) return false;

        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, word, idx + 1, r + 1, c)||
                     dfs(board, word, idx + 1, r, c + 1)||
                     dfs(board, word, idx + 1, r, c - 1)||
                     dfs(board, word, idx + 1, r - 1, c);
        board[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r<board.size(); r++){
            for(int c = 0; c<board[0].size(); c++){
                if(dfs(board, word, 0, r, c)){
                    return true;
                }
            }
        }
        return false;
    }
};
