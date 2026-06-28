class Solution {
public:
    int helper(int i, int j, string& text1, string& text2, vector<vector<int>>& memo){
        if(i == text1.length() || j == text2.length()) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        if(text1[i] == text2[j]){
            memo[i][j] = 1 + helper(i+1,j+1,text1,text2,memo);
        }else{
            memo[i][j] = max(helper(i+1,j,text1,text2,memo),helper(i,j+1,text1,text2,memo));
        }
        return memo[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length(),vector<int> (text2.length(),-1));
        return helper(0,0,text1,text2,memo);
    }
};
