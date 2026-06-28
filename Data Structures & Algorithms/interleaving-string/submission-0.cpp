class Solution {
public:
    bool helper(int i, int j, string& s1, string& s2, string& s3,
                vector<vector<int>>& dp) {

        if (i == s1.length() && j == s2.length()) return true;

        if (dp[i][j] != -1) return dp[i][j];

        int k = i + j;

        if (i == s1.length()) {
            if (s2[j] == s3[k]) {
                return dp[i][j] = helper(i, j + 1, s1, s2, s3, dp);
            }
            return dp[i][j] = false;
        }

        if (j == s2.length()) {
            if (s1[i] == s3[k]) {
                return dp[i][j] = helper(i + 1, j, s1, s2, s3, dp);
            }
            return dp[i][j] = false;
        }

        if (s3[k] == s1[i] && s3[k] == s2[j]) {
            return dp[i][j] =
                helper(i + 1, j, s1, s2, s3, dp) ||
                helper(i, j + 1, s1, s2, s3, dp);
        }

        if (s3[k] == s1[i]) {
            return dp[i][j] = helper(i + 1, j, s1, s2, s3, dp);
        }

        if (s3[k] == s2[j]) {
            return dp[i][j] = helper(i, j + 1, s1, s2, s3, dp);
        }

        return dp[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;

        vector<vector<int>> dp(s1.length() + 1,
                               vector<int>(s2.length() + 1, -1));

        return helper(0, 0, s1, s2, s3, dp);
    }
};