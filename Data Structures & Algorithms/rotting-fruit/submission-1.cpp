class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // No fresh oranges at all
        if (fresh == 0) return 0;

        // Fresh oranges exist but no rotten orange to start the process
        if (q.empty()) return -1;

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto &d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx >= 0 && nx < grid.size() &&
                        ny >= 0 && ny < grid[0].size() &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }

            ans++;
        }

        if (fresh > 0) return -1;
        return ans - 1;
    }
};