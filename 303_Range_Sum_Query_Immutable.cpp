class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int> nums) {
        dp.push_back(0);
        for(int i=0; i<nums.size(); i++) {
            int temp = dp.back() + nums[i];
            dp.push_back(temp);
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
