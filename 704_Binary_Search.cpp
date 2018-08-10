class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
//        int start = nums[i];
//        int end = nums[j];
//        int k = (j-i)/2;
//        int mid = nums[k];
        while(i<=j)
        {
            int mid = (i + j)/2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                i = mid + 1;
            else
                j = mid -1;                
        }
        return -1;
    }
};
