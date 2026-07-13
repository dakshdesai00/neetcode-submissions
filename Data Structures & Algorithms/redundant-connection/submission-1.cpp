class DSU {
    private: 
        vector<int> par;
        vector<int> size;
    public: 
        DSU(int n){
            size.resize(n + 1);
            par.resize(n + 1);
            for(int i = 0; i < n + 1; i++){
                par[i] = i;
                size[i] = 0;
            }
        }
        int ultimateParrent(int node1){
            if(par[node1] == node1) return node1;
            return par[node1] = ultimateParrent(par[node1]);
        }

        void unionBySize(int node1, int node2){
            int par1 = ultimateParrent(node1);
            int par2 = ultimateParrent(node2);
            if(size[par1] >= size[par2]){
                par[par2] = par1;
                size[par1] += size[par2];
            }else{
                par[par1] = par2;
                size[par2] += size[par1];
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU ds(edges.size());
        for(auto it: edges){
            if(ds.ultimateParrent(it[0]) == ds.ultimateParrent(it[1])){
                return it;
            }else{
                ds.unionBySize(it[0],it[1]);
            }
        }
        return {-1,-1};
    }
};
