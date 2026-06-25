class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        while(pq.size() >= 2){
            int big = pq.top(); pq.pop();
            int small = pq.top(); pq.pop();
            if(big == small) continue;
            else pq.push(big - small);
        }
        if(pq.size()) return pq.top();
        return 0;
    }
};
