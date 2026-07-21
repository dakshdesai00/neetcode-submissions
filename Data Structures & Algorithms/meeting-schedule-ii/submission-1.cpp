/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        int ans = 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });
        int prevEnd = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start >= prevEnd){
                prevEnd = intervals[i].end;
            }else{
                ans++;
                prevEnd = min(prevEnd, intervals[i].end);
            }
        }
        return ans + 1;
    }
};
