class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++)
            count[nums[i]]++;
        for(int i=0;i<nums.size();i++)
        {
            if(count[0] != 0)
            {
                nums[i] = 0;
                count[0]--;                
            }
            else if(count[1] != 0)
            {
                nums[i] = 1;
                count[1]--;                
            }
            else if(count[2] != 0)
            {
                nums[i] = 2;
                count[2]--;                
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int m=0;
        int k = nums.size()-1;
        while(m<=k)
        {
            if(nums[m] == 0)
            {
                swap(nums[i],nums[m]);
                i++;
                m++;
            }
            else if(nums[m] == 2)
            {
                swap(nums[m],nums[k]);
                k--;
            }
            else
                m++;
        }
    }
};
