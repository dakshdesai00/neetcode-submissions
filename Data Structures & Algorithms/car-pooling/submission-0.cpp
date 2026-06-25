class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pass(1001,0);
        for(auto it: trips){
            pass[it[1]] += it[0];
            pass[it[2]] -= it[0];
        }
        int curr = 0;
        for(int i = 0; i < 1000; i++){
            curr += pass[i];
            if(curr > capacity) return false;
        }
        return true;
    }
};