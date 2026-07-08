class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int colums = grid[0].size();
        int minutes = -1;
        int freshOranges = 0;
        queue<pair<int, int>>holder;
        int dx[] = {1,-1, 0, 0};
        int dy[] = {0,0, 1, -1};


        for(int row = 0; row<rows; row++){
            for(int colum = 0; colum<colums; colum++){
                if(grid[row][colum] == 2){
                    holder.push({row, colum});
                }else if(grid[row][colum] == 1){
                    freshOranges++;
                }
            }
        }

        if(!freshOranges)return 0;

        while(!holder.empty()){
            int h_size = holder.size();
            minutes++;
            while(h_size--){
                auto [row, colum] = holder.front();
                holder.pop();
               for(int dir = 0; dir<4; dir++){
                    int dirX = dx[dir] + row;
                    int dirY = dy[dir] + colum;
                    if(dirX >= 0 && dirX < rows && dirY >= 0 && dirY < colums && grid[dirX][dirY] == 1){
                        grid[dirX][dirY] = 2;
                        freshOranges--;
                        holder.push({dirX, dirY});
                    }
                }
            }

            
        }

        return freshOranges == 0 ?  minutes : -1;
    }
};
