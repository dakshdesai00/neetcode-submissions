class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        queue<pair<int,pair<int,char>>> cooldown;
        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});
        string res = "";
        int ans = 0;
        while(!pq.empty() || !cooldown.empty()){
            if(!cooldown.empty()){
                if(ans == cooldown.front().first){
                    pq.push(cooldown.front().second);
                    pq.pop();
                }
                if(pq.empty()) return res;
            }
            if(!pq.empty()){
                pair<int,char> top = pq.top();
                pq.pop();
                if(top.first >= 2){
                    top.first -= 2;
                    if(res.length() >= 1 && res[res.length() - 1] == top.second) return res;
                    res += top.second;
                    res += top.second;
                    ans += 2;
                    if(top.first > 0){
                        cooldown.push({ans + 3,top});
                    }
                }else if(top.first >= 1){
                    top.first -= 1;
                    if(res.length() >= 1 && res[res.length() - 1] == top.second) return res;
                    res += top.second;
                    ans += 1;
                    if(top.first > 0){
                        cooldown.push({ans + 2, top});
                    }
                }
            }
        }
        return res;
    }
};