int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int i = 0;
        int j = 0;
        int res = INT_MAX;
        while(i<nums.size())
        {
            while(sum<s && i<=j)
            {
                sum += nums[j];
                j++;     
            }
            res = min(res,j-i);
            sum -= nums[i];
            i++;
        }
        return (res != INT_MAX) ? res : 0;
    }