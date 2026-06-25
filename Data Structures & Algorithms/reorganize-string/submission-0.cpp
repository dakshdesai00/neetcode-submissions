class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for(auto it : s) freq[it - 'a']++;
        

        priority_queue<pair<int, int>> sch;
        queue<pair<int, pair<int, int>>> cooldown;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) sch.push({freq[i], i});
        }
        
        int ans = 0;
        string res = "";
        while(!sch.empty() || !cooldown.empty()){
            if(!cooldown.empty() && cooldown.front().first == ans){
                sch.push(cooldown.front().second);
                cooldown.pop();
            }
        
            if(!sch.empty()){
                pair<int, int> top = sch.top();
                sch.pop();
                res += top.second + 'a';
                if(res.length() > 1){
                    if(res[res.length() - 1] == res[res.length() - 2]) return "";
                }
                top.first--; 
                if(top.first > 0){
                    cooldown.push({ans + 2, top}); 
                }
            }
            ans++;
        }
        return res;
    }
};