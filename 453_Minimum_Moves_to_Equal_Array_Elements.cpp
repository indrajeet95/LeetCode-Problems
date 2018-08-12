//basic idea is to think that rather than increment n-1 elements by 1 and make everything equal to the max element why dont you decrement just 1 element and count it as a step and find out how many steps are required to make everything equal to the min element
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = nums[0];
        int sum = nums[0];;
        for(int i=1;i<nums.size();i++)
        {
            sum += nums[i];
            if(min > nums[i])
                min = nums[i];
        }
        return sum - nums.size()*min;
    }
};