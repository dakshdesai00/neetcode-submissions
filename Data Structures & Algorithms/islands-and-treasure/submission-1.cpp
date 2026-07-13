class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) q.push({0,{i,j}});
            }
        }
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            pair<int,pair<int,int>> node = q.front();
            q.pop();
            int dist = node.first;
            int x = node.second.first;
            int y = node.second.second;
            for(auto it: dir){
                int nx = x + it[0];
                int ny = y + it[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != -1){
                    if(dist + 1 < grid[nx][ny]){
                        grid[nx][ny] = dist + 1;
                        q.push({grid[nx][ny],{nx,ny}});
                    }
                }
            }
        }
    }
};
