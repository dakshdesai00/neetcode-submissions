#include <vector>
#include <algorithm>
#include <stack>
#include <functional>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, int>> in;
        for (int i = 0; i < n; i++) {
            in.push_back({position[i], speed[i]});
        }
        
        // Sort descending by position so we process from closest to farthest from target
        sort(in.begin(), in.end(), greater<pair<int, int>>());
        
        stack<double> timeStack;
        
        for (int i = 0; i < n; i++) {
            // CRITICAL: Cast to double to prevent integer division truncation
            double currTime = (double)(target - in[i].first) / in[i].second;
            
            if (timeStack.empty()) {
                timeStack.push(currTime);
            } else {
                // If the current car takes MORE time than the fleet in front of it, 
                // it cannot catch up. It forms a brand new fleet header.
                if (currTime > timeStack.top()) {
                    timeStack.push(currTime);
                }
                // If currTime <= timeStack.top(), it catches up and becomes part 
                // of the existing fleet. We don't push it because it is limited by the slower car ahead.
            }
        }
        
        // The number of remaining elements in the stack represents the total fleets
        return timeStack.size();
    }
};
