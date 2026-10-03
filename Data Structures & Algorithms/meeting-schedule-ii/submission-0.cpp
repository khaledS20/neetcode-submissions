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
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>>hold;
        // hold.push(intervals[0])

        for(int i = 0; i<intervals.size(); i++){
            if(!hold.empty() && hold.top() <= intervals[i].start){
                hold.pop();
            }
            hold.push(intervals[i].end);
        }

        return hold.size();        
    }
};
