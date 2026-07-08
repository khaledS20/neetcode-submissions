class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<pair<int, int>>holder;
        int maxArea = 0;

        for(int i =0; i<n; i++)
        {
            int start = i;

            while(!holder.empty() && holder.top().second > heights[i])
            {
                auto [index, height] = holder.top();
                holder.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            holder.push({start, heights[i]});
        }

        while(!holder.empty())
        {
            auto [index , height] = holder.top();
            holder.pop();
            maxArea = max(maxArea, height * (n - index));
        }

        return maxArea;
    }
};
