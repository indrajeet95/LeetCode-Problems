class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curr_min = res;
        int curr_max = res;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(curr_min,curr_max);
            curr_max = max(nums[i],curr_max*nums[i]);
            curr_min = min(nums[i],curr_min*nums[i]);
            res = max(res,curr_max);
        }
        return res;
    }
};