class Solution {
public:
    void dfs(vector<vector<char>>&b, int r, int c){
        int m = b.size();
        int n = b[0].size();

        if(r < 0 || c < 0 || r>= m || c >= n || b[r][c] != 'O')return;

        b[r][c] = '#';
        dfs(b, r - 1, c);       
        dfs(b, r + 1, c);       
        dfs(b, r, c + 1);       
        dfs(b, r, c - 1);       
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O'){
                    dfs(board, i, j);
                }
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
               if(board[i][j] == 'O'){
                board[i][j] = 'X';
               }else if(board[i][j] == '#'){
                board[i][j] = 'O';
               }
            }
        }
    }
};
