class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    q.push({i,j});
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto &d : dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && nx < m &&
                   ny >= 0 && ny < n &&
                   grid[nx][ny] == INT_MAX){

                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};