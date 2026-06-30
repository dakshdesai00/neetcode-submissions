class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if(vis[i][j] != -1) return;
        vis[i][j] = 1;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto it: dir){
            int nx = i + it[0];
            int ny = j + it[1];
            if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == '1'){
                dfs(grid,vis,nx,ny);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(vis[i][j] != 1 && grid[i][j] == '1'){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};
