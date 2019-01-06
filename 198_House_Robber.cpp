//Evernote times
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        //memo is of size n+1 because memo[i] signifies the max amount of money that you could have stole till this point but not including the current house
        vector<int> memo(n+1);
        memo[0] = 0;
        memo[1] = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            memo[i+1] = max(memo[i], nums[i] + memo[i-1]);
        }
        return memo[nums.size()];
    }
};
//but this also makes sense 
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        vector<int> res(len,0);
        res[0] = nums[0];
        res[1] = max(nums[0],nums[1]);
        for(int i = 2;i<len;i++)
            res[i] = max(res[i-2] + nums[i],res[i-1]);
        return res[len-1];
    }
};