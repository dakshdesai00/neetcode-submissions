#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto it : tasks) freq[it - 'A']++;
        
        // Max-heap stores {frequency, task_id}
        priority_queue<pair<int, int>> sch;
        // Cooldown stores {available_time, {remaining_frequency, task_id}}
        queue<pair<int, pair<int, int>>> cooldown;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) sch.push({freq[i], i});
        }
        
        int ans = 0;
        while(!sch.empty() || !cooldown.empty()){
            // 1. Release tasks from cooldown if their wait time is over
            if(!cooldown.empty() && cooldown.front().first == ans){
                sch.push(cooldown.front().second);
                cooldown.pop();
            }
            
            // 2. Process the most frequent available task
            if(!sch.empty()){
                pair<int, int> top = sch.top();
                sch.pop();
                
                top.first--; // Execute 1 unit of this task
                
                // Only put it in cooldown if there are remaining instances left
                if(top.first > 0){
                    cooldown.push({ans + n + 1, top}); 
                }
            }
            
            // 3. Move to the next CPU clock cycle
            ans++;
        }
        return ans;
    }
};
