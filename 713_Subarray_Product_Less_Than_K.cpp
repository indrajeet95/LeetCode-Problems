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


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int count = 0;
        int n = nums.size();
        int i =0;
        int j = 0;
        while(j<n)
        {
            product *= nums[j];
            while(i<=j && product >= k)
            {
                product = product/nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
};
