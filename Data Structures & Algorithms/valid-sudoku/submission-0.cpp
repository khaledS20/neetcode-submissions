class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i<9; i++){
            unordered_map<char, int>freq;
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.')freq[board[i][j]]++;
                if(freq[board[i][j]] > 1) return false;
            }
        }
        for(int i = 0; i<9; i++){
            unordered_map<char, int>freq;
            for(int j = 0; j<9; j++){
                if(board[j][i] != '.')freq[board[j][i]]++;
                if(freq[board[j][i]] > 1) return false;
            }
        }


        for(int i = 0; i<9; i+=3){
            for(int j = 0; j<9; j+=3){
                unordered_map<char, int>freq;

                for(int a = 0; a<3; a++){
                    for(int b = 0; b<3; b++){
                        if(board[i + a][j + b] != '.')freq[board[i + a][j + b]]++;
                        if(freq[board[i + a][j + b]] > 1) return false;   
                    }
                }
            }
        }

        return true;
    }
};
