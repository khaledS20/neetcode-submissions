
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> hold;
        int minute = -1;
        int fresh = 0;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        // Collect all rotten oranges and count fresh oranges.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    hold.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        // Multi-source BFS.
        while (!hold.empty()) {
            int size = hold.size();
            minute++;

            while (size--) {
                auto [a, b] = hold.front();
                hold.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = a + dx[i];
                    int ny = b + dy[i];

                    if (nx >= 0 && ny >= 0 &&
                        nx < n && ny < m &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        hold.push({nx, ny});
                    }
                }
            }
        }

        return fresh == 0 ? minute : -1;
    }
};