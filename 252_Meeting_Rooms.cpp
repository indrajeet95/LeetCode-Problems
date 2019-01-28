/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool comp(Interval i, Interval j)
    {
        return i.start < j.start;        
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return true;
        sort(intervals.begin(), intervals.end(), comp);
        for(int i=0; i<intervals.size()-1; i++)
        {
            if(intervals[i].end <= intervals[i+1].start)
                continue;
            else
                return false;
        }
        return true;
    }
};