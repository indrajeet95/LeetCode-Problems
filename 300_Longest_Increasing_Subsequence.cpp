class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size());
        dp[0] = 1;
        for(int i=1; i<nums.size(); i++)
        {
            int maxi = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                    maxi = max(maxi, dp[j]);
            }
            dp[i] = maxi + 1;
        }
        int res = dp[0];
        for(int i=1; i<dp.size(); i++)
        {
            if(res < dp[i])
                res = dp[i];
        }
        return res;
    }
};

class Solution {
public:
    //geeksforgeeks
    //
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}    
};
