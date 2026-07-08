class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>rows(n, 0);
        vector<int>cols(m, 0);

        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(matrix[row][col] == 0){
                    rows[row] = 1;
                    cols[col] = 1;
                }
            }
        }
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(rows[row] || cols[col]){
                    matrix[row][col] = 0;
                }
            }
        }


    }
};
