class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // rows
        int m = matrix[0].size(); // colums

        int top = 0;
        int bottom = n - 1;

        while(top < bottom){
            for(int i = 0; i<m; i++){
                swap(matrix[bottom][i], matrix[top][i]);
            }
            top++;
            bottom--;
        }

        for(int row = 0; row<n; row++){
            for(int col = row + 1; col<m; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};
