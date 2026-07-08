class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>>q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0)q.push({i, j});
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [a, b] = q.front();
                q.pop();
                for(int i = 0; i<4; i++){
                    int nx = dx[i] + a;
                    int ny = dy[i] + b;
                    if(ny >= 0 && nx >= 0 && ny < n && nx < m && grid[nx][ny] == INT_MAX){
                        grid[nx][ny] = grid[a][b] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
};
