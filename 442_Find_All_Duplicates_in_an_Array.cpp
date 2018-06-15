class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            int m = abs(nums[i])-1;
            if(nums[m]>0)
                nums[m] *= -1;
            else
                res.push_back(abs(nums[i]));
        }
        return res;

    }
};
