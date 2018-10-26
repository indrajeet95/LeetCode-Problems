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
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.size() == 0)
        {
            res.push_back(newInterval);
            return res;
        }
        for(int i=0; i<intervals.size(); i++)
        {
            if(intervals[i].end < newInterval.start)
                res.push_back(intervals[i]);
            else if(intervals[i].start > newInterval.end)
            {
                res.push_back(newInterval);
                for(int j=i; j< intervals.size(); j++)
                    res.push_back(intervals[j]);
                return res;
            }
            else
            {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};