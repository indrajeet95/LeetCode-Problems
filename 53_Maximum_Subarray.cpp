class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum;
        int sum;
        maxsum = sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum = max(sum + nums[i],nums[i]);
            if(sum > maxsum)
                maxsum = sum;
        }
        return maxsum;
    }
};
