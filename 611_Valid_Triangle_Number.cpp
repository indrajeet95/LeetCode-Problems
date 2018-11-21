class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int tail = nums.size() - 1; tail>=0; tail--)
        {
            int j = 0;
            int k = tail - 1;
            while(j < k)
            {
                if(nums[j] + nums[k] > nums[tail])
                {
                    res += k - j;
                    k--;
                }
                else
                    j++;
            }
        }
        return res;
    }
};