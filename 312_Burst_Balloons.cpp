class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> maxcoins (nums.size(), vector<int> (nums.size(),0));
        for(int len=1;len <= n;len++)
        {
            for(int left = 1; left <= n - len + 1;left++)
            {
                int right = left + len -1;
                for(int k=left;k<=right;k++)
                {
                    maxcoins[left][right] = max(maxcoins[left][right], nums[left-1]*nums[k]*nums[right+1] + maxcoins[left][k-1] + maxcoins[k+1][right]);
                }
            }
        }
        return maxcoins[1][n];
    }
};