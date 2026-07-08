class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&h, vector<vector<bool>>&v, int prevh){
        int m = h.size();
        int n = h[0].size();

        if(r<0 || r>=m|| c < 0 || c>= n || v[r][c] || prevh > h[r][c]){
            return;
        }

        v[r][c] = true;

        dfs(r + 1, c, h, v, h[r][c]);
        dfs(r - 1, c, h, v, h[r][c]);
        dfs(r, c - 1, h, v,  h[r][c]);
        dfs(r, c + 1, h, v,  h[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        
        int m = h.size();
        int n = h[0].size();

        vector<vector<bool>>pac(m, vector<bool>(n, false));
        vector<vector<bool>>atl(m, vector<bool>(n, false));

        for(int i = 0; i<n; i++){
            dfs(0, i, h, pac, h[0][i]);
            dfs(m-1, i, h, atl, h[m-1][i]);
        }
        for(int i = 0; i<m; i++){
            dfs(i, 0, h, pac, h[i][0]);
            dfs(i, n-1, h, atl, h[i][n-1]);
        }

        vector<vector<int>>result;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(pac[i][j] && atl[i][j]){
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};