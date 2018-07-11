class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        vector<int> res(len,0);
        res[0] = nums[0];
        res[1] = max(nums[0],nums[1]);
        for(int i = 2;i<len;i++)
            res[i] = max(res[i-2] + nums[i],res[i-1]);
        return res[len-1];
    }
};