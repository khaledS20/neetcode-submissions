#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& visited, int prevHeight, vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        // Base cases: Out of bounds, already visited, or height is lower (cannot flow uphill)
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        visited[r][c] = true;

        // Explore all 4 directions
        dfs(r + 1, c, visited, heights[r][c], heights);
        dfs(r - 1, c, visited, heights[r][c], heights);
        dfs(r, c + 1, visited, heights[r][c], heights);
        dfs(r, c - 1, visited, heights[r][c], heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Start DFS from horizontal borders (Top for Pacific, Bottom for Atlantic)
        for (int j = 0; j < n; j++) {
            dfs(0, j, pacific, heights[0][j], heights);
            dfs(m - 1, j, atlantic, heights[m - 1][j], heights);
        }

        // Start DFS from vertical borders (Left for Pacific, Right for Atlantic)
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific, heights[i][0], heights);
            dfs(i, n - 1, atlantic, heights[i][n - 1], heights);
        }

        // Find cells that can reach both
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};