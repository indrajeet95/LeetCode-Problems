class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            int m = abs(nums[i]) - 1;
            if(nums[m]>0)
                nums[m] *= -1;
        }
        for(int j=0;j<size;j++)
            if(nums[j]>0)
                res.push_back(j+1);
        return res;
    }
};
