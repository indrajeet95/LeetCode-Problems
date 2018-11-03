class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i< n; i++)
        {
            int j = i;
            int k = getIndex(i,nums);
            while(nums[i]*nums[k]>0 && nums[i]*nums[getIndex(k,nums)]>0)
            {
                if(j == k)
                {
                    if(j == getIndex(j,nums))
                        break;
                    return true;
                }
                j = getIndex(j,nums);
                k = getIndex(getIndex(k,nums),nums);
            }
        }
        return false;
    }
    int getIndex(int i, vector<int> nums)
    {
        int n = nums.size();
        return i + nums[i]>=0 ? (i + nums[i])%n : n + (i + nums[i])%n;
    }
};