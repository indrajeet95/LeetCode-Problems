class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int no = nums.size();
        int total = (no*(no+1))/2;
        for(int i=0;i<nums.size();i++)
            total -= nums[i];
        return total;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int no = nums.size();
//        vector<int> temp;
//        for(int i=0;i<no;i++)
//           temp[i] = i;
        int res = no;
        for(int j=0;j<no;j++)
            res ^= j ^ nums[j];
        return res;
    }
};