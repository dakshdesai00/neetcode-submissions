class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            for(auto it: dir){
                int nx = node.first + it[0];     
                int ny = node.second + it[1];
                if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] != -1){
                    if(grid[nx][ny] > 1 + grid[node.first][node.second]){
                        grid[nx][ny] = 1 + grid[node.first][node.second];
                        q.push({nx,ny});
                    }
                }         
            }
        }
    }
};
