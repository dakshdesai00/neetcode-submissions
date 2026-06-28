class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo){
        if(memo[i][j] != -1) return memo[i][j];

        vector<pair<int,int>> loc = {
            {-1,0}, {1,0},
            {0,-1}, {0,1}
        };

        int ways = 1;

        for(int k = 0; k < 4; k++){
            int newX = i + loc[k].first;
            int newY = j + loc[k].second;

            if(newX < 0 || newY < 0 ||
               newX >= matrix.size() || newY >= matrix[0].size() ||
               matrix[newX][newY] <= matrix[i][j])
                continue;

            ways = max(ways, 1 + dfs(newX, newY, matrix, memo));
        }

        return memo[i][j] = ways;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans = max(ans, dfs(i, j, matrix, dp));

        return ans;
    }
};