class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        queue<pair<int, int>>hold;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    hold.push({i, j});
                }
            }
        }

        while(!hold.empty()){
            int size = hold.size();
            while(size--){
                auto [a, b] = hold.front();
                hold.pop();
                for(int i = 0; i<4; i++){
                    int nx = a + dx[i];
                    int ny = b + dy[i];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == INT_MAX){
                        // fresh--;
                        grid[nx][ny]=grid[a][b] + 1;
                        hold.push({nx, ny});
                    }
                }
            }
        }
    }
};
