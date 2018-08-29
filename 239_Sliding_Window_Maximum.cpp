class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            //[i-k+1,i]
            while(!dq.empty() && nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
                res.push_back(nums[dq.front()]);
            if(dq.front()<=i-k+1)
                dq.pop_front();
        }
        return res;
    }
};

