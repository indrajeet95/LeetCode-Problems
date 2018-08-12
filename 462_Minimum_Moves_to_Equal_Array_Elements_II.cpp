//median is the key
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int lsum = 0;
        int rsum = 0;
        int lcount = 0;
        int rcount = 0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]<nums[size/2])
            {
                lsum += nums[i];
                lcount++;                
            }
            else
            {
                rcount++;
                rsum += nums[i];
            }
        }
        return lcount*nums[size/2] - lsum + rsum - rcount*nums[size/2];
    }
};