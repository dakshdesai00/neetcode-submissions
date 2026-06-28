class Solution {
public:
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;

        if(dp[i][j + 1] != -1) return dp[i][j + 1];

        int ans = helper(i + 1, j, nums, dp);

        if(j == -1 || nums[i] > nums[j]){
            ans = max(ans, 1 + helper(i + 1, i, nums, dp));
        }

        return dp[i][j + 1] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return helper(0, -1, nums, dp);
    }
};