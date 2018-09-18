int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int i = 0;
        int j = 0;
        int res = INT_MAX;
        while(i<nums.size())
        {
            while(sum<s && i<=j)
            {
                sum += nums[j];
                j++;     
            }
            res = min(res,j-i);
            sum -= nums[i];
            i++;
        }
        return (res != INT_MAX) ? res : 0;
    }



    class Solution {
public:

int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= s) {
            ans = min(ans, i + 1 - left);
            sum -= nums[left++];
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}
};