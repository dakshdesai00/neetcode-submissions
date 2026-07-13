class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,bool> vis;
        for(auto edge: edges){
            if(vis[edge[0]] && vis[edge[1]]){
                return edge;
            }else {
                vis[edge[0]] = true;
                vis[edge[1]] = true;
            }
        }
        return {-1,-1};
    }
};
