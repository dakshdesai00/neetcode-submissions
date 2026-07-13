class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int,vector<vector<int>>> mp;
        for(auto it: times){
            mp[it[0]].push_back({it[1],it[2]});
        }
        pq.push({0,k});
        time[k] = 0;
        while(!pq.empty()){
    auto [t, node] = pq.top();
    pq.pop();

    if(t > time[node]) continue;

    for(auto &it : mp[node]){
        int nxt = it[0];
        int wt = it[1];

        if(time[nxt] > t + wt){
            time[nxt] = t + wt;
            pq.push({time[nxt], nxt});
        }
    }
}
        int ans = INT_MIN;
        for(int i = 1; i < time.size(); i++){
            ans = max(ans,time[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
