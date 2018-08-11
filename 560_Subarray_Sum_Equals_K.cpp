class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int counter = 0;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> sums;
            int sum = 0;
            for(int j=i;j<nums.size();j++)
            {
                sum += nums[j];
                sums.push_back(sum);
            }
            counter += count(sums.begin(),sums.end(),k);
        }
        return counter;
    }
};

//

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> maps;
        maps[0] = 1;
        int sum = 0;
        int counter = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            counter += maps[sum-k];
            maps[sum]++;
        }
        return counter;
    }
};