class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int top = 0;
        int bottom = matrix.size()-1;
        int row = -1;
        while(top <= bottom){
            int mid = (top + bottom) / 2;
            if(matrix[mid][0] <= target && matrix[mid].back() >= target){
                row = mid;
                break;
            }else if(matrix[mid][0] > target){
                bottom = mid - 1;
            }else{
                top = mid + 1;
            }
        }

        if(row == -1) return false;

        int left = 0;
        int right = matrix[0].size()-1;

        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }
};
