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
    int minMeetingRooms(vector<Interval>& intervals) {
        int res = 0;
        vector<int> starter(intervals.size(),0);
        vector<int> ender(intervals.size(),0);
        for(int i=0; i<intervals.size(); i++)
        {
            starter[i] = intervals[i].start;
            ender[i] = intervals[i].end;
        }
        sort(starter.begin(), starter.end());
        sort(ender.begin(), ender.end());
        int i=0, j =0;
        while(i < starter.size())
        {
            if(starter[i] >= ender[j])
            {
                res--;
                j++;
            }
            res++;
            i++;
        }
        return res;
    }
};
//1  2  3  8 10 11
//7 10 12 19 20 30

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
    static bool compare1(Interval a, Interval b){
        return a.start < b.start;
    }
    static bool compare(int a, int b) {
        return a > b;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        sort(intervals.begin(), intervals.end(), compare1);
        min_heap.push(intervals[0].end);
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i].start >= min_heap.top())
                min_heap.pop();
            min_heap.push(intervals[i].end);
        }
        return min_heap.size();
    }
};

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
    static bool compare1(Interval a, Interval b){
        return a.start < b.start;
    }
    struct comp{
        bool operator()(int a, int b)
        {
            return a>b;
        }
    };
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;
        priority_queue<int, vector<int>, comp> min_heap;
        sort(intervals.begin(), intervals.end(), compare1);
        min_heap.push(intervals[0].end);
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i].start >= min_heap.top())
                min_heap.pop();
            min_heap.push(intervals[i].end);
        }
        return min_heap.size();
    }
};