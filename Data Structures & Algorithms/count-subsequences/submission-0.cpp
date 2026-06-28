class Solution {
public:
    int helper(int i, int j, string& s, string& t, vector<vector<int>>& memo){
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int ways = 0;
        if(s[i] == t[j]){
            ways += helper(i + 1, j + 1, s,t,memo);
            ways += helper(i + 1, j, s,t,memo);
        } 
        else{
            ways += helper(i + 1, j, s,t,memo);
        }
        return memo[i][j] = ways;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> memo (s.length(), vector<int>(t.length(),-1));
        return helper(0,0,s,t,memo);
    }
};
