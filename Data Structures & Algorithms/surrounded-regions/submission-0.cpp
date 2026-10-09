class Solution {
public:
    void dfs(vector<vector<char>>&board, int row, int col){
        int rows = board.size();
        int cols = board[0].size();

        if(row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O')return;

        board[row][col] = '#';

        dfs(board, row + 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
        dfs(board, row - 1, col);
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if((j == 0 || i == 0 || i == rows-1 || cols-1 == j) && board[i][j] == 'O'){
                    dfs(board, i, j);
                }
            }
        }

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }        
    }
};
