/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a, Interval b)
{
    return (a.start < b.start);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int size = intervals.size();
        if (size <= 0)
            return res;
        sort(intervals.begin(),intervals.end(), compare);
        res.push_back(intervals[0]);
        for(int i=1;i<size;i++)
        {
            if(res.back().end < intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end = max(res.back().end,intervals[i].end);
        }
        return res;
    }
};