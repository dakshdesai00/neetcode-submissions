class Disjointset{
    private:
        vector<int> parent;
        vector<int> size;
    public: 
        Disjointset(int n){
            size.resize(n);
            parent.resize(n);
            for(int i = 0; i < n; i++){
                size[i] = 1;
                parent[i] = i;
            }
        }
        int findUltimateParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionBySize(int node1, int node2){
            int p1 = findUltimateParent(node1);
            int p2 = findUltimateParent(node2);
            if(p1 == p2) return;
            else if(size[p1] < size[p2]){
                size[p2] += size[p1];
                parent[p1] = p2;
            }
            else if(size[p1] >= size[p2]){
                size[p1] += size[p2];
                parent[p2] = p1;
            }
        }

        int numOfComponents(){
            int cnt = 0;
            for(int i = 0; i < parent.size(); i++){
                if(parent[i] == i) cnt++;
            }
            return cnt;
        }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Disjointset ds(n);
        for(int i = 0; i < edges.size(); i++){
            ds.unionBySize(edges[i][0],edges[i][1]);
        }
        return ds.numOfComponents();
    }
};
