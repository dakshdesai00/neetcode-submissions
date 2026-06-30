class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (q.size() == 0) return -1;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (auto it : dir) {
                    int nx = x + it[0];
                    int ny = y + it[1];
                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
                        grid[nx][ny] == 1) {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            ans++;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans - 1;
    }
};
