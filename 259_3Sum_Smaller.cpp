class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int count = 0;
        if(nums.size() <3)
            return NULL;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                int cur_sum = nums[i] + nums[l] + nums[r];
                if(cur_sum < target)
                {
                    count+=r-l;
                    l++;
                }
                else
                    r--;
//                while(nums[l] == nums[l-1])
//                    l++;
//                while(nums[r] == nums[r+1])
//                    r--;
            }
        }
        return count;
        
    }
};
