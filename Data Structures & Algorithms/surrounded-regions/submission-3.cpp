class Solution {
public:
    void dfs(vector<vector<char>> &board, int row, int colum){
        int rows = board.size();
        int colums = board[0].size();

        if(row < 0 || row >= rows || colum < 0 || colum >= colums || board[row][colum] != 'O')
            return;
        
        board[row][colum] = '#';
        dfs(board, row - 1, colum);
        dfs(board, row, colum - 1);
        dfs(board, row + 1, colum);
        dfs(board, row, colum + 1);
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int colums = board[0].size();

        for(int row = 0; row<rows; row++){
            for(int colum = 0; colum<colums; colum++){
                if((row == 0 || row == rows-1 || colum == 0 || colum == colums-1) && board[row][colum] == 'O'){
                    dfs(board, row, colum);
                }
            }
        }
        for(int row = 0; row<rows; row++){
            for(int colum = 0; colum<colums; colum++){
                if(board[row][colum] == 'O'){
                    board[row][colum] = 'X';
                }else if(board[row][colum] == '#'){
                    board[row][colum] = 'O';
                }
            }
        }


    }
};
