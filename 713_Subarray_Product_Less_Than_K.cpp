class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int proc = 1;
        while(j<nums.size())
        {
            proc *= nums[j];
            while(proc>=k && i<=j)
                proc /= nums[i++];
            count += j-i+1;
            j++;
        }
        return count;
    }
};
