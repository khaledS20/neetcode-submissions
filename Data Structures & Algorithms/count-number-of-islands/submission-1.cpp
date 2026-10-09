class Solution {
public:
    void dfs(vector<vector<char>>&board, int row, int col){
        int rows = board.size();
        int cols = board[0].size();

        if(row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != '1')return;

        board[row][col] = '0';

        dfs(board, row + 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
        dfs(board, row - 1, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int c = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    c++;
                    dfs(grid, i, j);
                }
            }
        }
        return c;
    }
};
