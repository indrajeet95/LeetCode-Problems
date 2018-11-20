

class MovingAverage {
private:
    queue<int> nums;
    double sum;
    int avgsize;
    
public:
    /** Initialize your data structure here. */
    //MovingAverage(int size):avgsize(size),sum(0) {}
    MovingAverage(int size) {
        avgsize = size;
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        nums.push(val);
        int qsize = (int)nums.size();
        if(qsize <= avgsize)
        {
            return sum/qsize;
        }
        else {
            sum -= nums.front();
            nums.pop();
            return sum/avgsize;
        }
    }
};

