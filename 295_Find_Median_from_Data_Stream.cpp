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


class MedianFinder {
public:
    multiset<int> set;
    multiset<int>::iterator left,right;
    /** initialize your data structure here. */
    MedianFinder() {
        //left = set.end();
        //right = set.end();
    }
    
    void addNum(int num) {
        const size_t n = set.size();
        set.insert(num);
        if(n == 0)
        {
            left = right = set.begin();
        }
        else if(n%2 == 1)
        {
            if(num < *left)
                left--;
            else
                right++;
        }
        else
        {
            if(num>*left && num <*right)
            {
                left++;
                right--;
            }
            else if(num>=*right)
                left++;
            else
                left = --right;
        }
    }
    
    double findMedian() {
        return (double)(*left + *right)/2;
    }
};
