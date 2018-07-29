//hamming distance is straightforward. we need to compute the number of ones in a XOR b
//so if two bits are different they shall contribute to the result
//rather than seeing all possible combinations between numbers we focus on seeing how much does the ith bit contribute to result
//iterate through each bit and check every number's ith bit and if its a one move it to a set and if not move it to another set
//now we can choose any one element from each set which will give us one possible combination for the result
//pC1*qC1 = p*q keeps on adding to result
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<32;i++)
        {
            int ones = 0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j] & (1<<i))
                    ones++;
            }
            int zeros = nums.size() - ones;
            res += zeros*ones;
        }
        return res;
    }
};