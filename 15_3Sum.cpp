class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len<3)
            return res;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<len-2)
        {
            if(nums[i]>0)
                break;
            int j = i+1;
            int k=len-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0 && j<k)
                {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    res.push_back(temp);
                }
                if(sum<=0 && j<k)
                    while(nums[j] == nums[++j] && j<k);
                if(sum>0)
                    while(nums[k] == nums[--k] && j<k);
            }
            while(nums[i] == nums[++i] && i<len-2);
        }
        return res;
    }
};

//revision this is a better solution i guess
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(unsigned int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                int target = -nums[i];
                if(nums[l] + nums[r] > target)
                    r--;
                else if(nums[l] + nums[r] < target)
                    l++;
                else
                {
                    res.push_back(vector<int> {nums[i],nums[l],nums[r]});
                    while(nums[l] == nums[l+1])
                        l++;
                    while(nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
        
    }
};
