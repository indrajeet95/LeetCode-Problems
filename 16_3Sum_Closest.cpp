class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return NULL;
        sort(nums.begin(),nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.size();i++)
        {
            if(i>=0 && nums[i] == nums[i-1])
                continue;
            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                int cur_sum = nums[l] + nums[r] + nums[i];
                if(cur_sum == target)
                    return cur_sum;
                if(abs(cur_sum - target) < abs(closest_sum - target))
                    closest_sum = cur_sum;
                if(cur_sum < target)
                    l++;
                else if(cur_sum > target)
                    r--;
            }
        }
        return closest_sum;
        
    }
};