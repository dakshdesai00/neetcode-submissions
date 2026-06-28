class Solution {
public:
    int ways(vector<int>& nums, int target, int i, vector<vector<int>>& memo){
        if(i == nums.size())
            return target == 0;

        if(target < -1000 || target > 1000)
            return 0;

        if(memo[i][target + 1000] != -1)
            return memo[i][target + 1000];

        return memo[i][target + 1000] =
            ways(nums, target - nums[i], i + 1, memo) +
            ways(nums, target + nums[i], i + 1, memo);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> memo(nums.size(), vector<int>(2001, -1));
        return ways(nums, target, 0, memo);
    }
};