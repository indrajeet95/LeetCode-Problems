class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        int len = nums.size();
        if(target > nums[len-1])
            return len;
        while(index!=nums.size())
        {
            if(target == nums[index])
                return index;
            else if(target > nums[index])
                index++;
            else if(target < nums[index])
                return index;
        }
    }
};
