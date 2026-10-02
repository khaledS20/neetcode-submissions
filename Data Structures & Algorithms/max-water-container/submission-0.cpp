class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int maxArea = 0;

        while(left < right){
            int w = right - left;
            int h = min(heights[left], heights[right]);
            maxArea = max(maxArea, w *h);

            if(heights[left] < heights[right])left++;
            else right--;
        }

        return maxArea;
    }
};
