class MedianFinder {
    priority_queue<int> lo;
    priority_queue<int,vector<int>, greater<int>> hi;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(lo.size()<hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if(lo.size() == hi.size())
        {
            return (double)(lo.top()+hi.top())/2;
        }
        else
            return lo.top();
    }
};
