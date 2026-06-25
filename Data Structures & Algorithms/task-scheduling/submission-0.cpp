class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto it: tasks) freq[it-'A']++;
        priority_queue<pair<int,int>> sch;
        queue<pair<int,pair<int,int>>> cooldown;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) sch.push({freq[i],i});
        }
        int ans = 0;
        while(!sch.empty() || !cooldown.empty()){
            if(!cooldown.empty()){
                if(cooldown.front().first == ans){
                    sch.push(cooldown.front().second);
                    cooldown.pop();
                }
            }
            if(!sch.empty()){
                pair<int,int> top = sch.top();
                sch.pop();
                if(top.first >= 1){
                    top.first--;
                    cooldown.push({ans + n,top});
                }
            }
            ans++;
        }
        return ans-1;
    }
};
