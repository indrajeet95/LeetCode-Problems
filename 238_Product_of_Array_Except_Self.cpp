class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),0);
        int mul = 1;
        int count = 0;
        vector<int> pos;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                pos.push_back(i);                
            if(nums[i] != 0)
            mul *= nums[i];
        }
        if(pos.size() > 1)
            return output;
        else if(pos.size() == 1)
        {
            output[pos[0]] = mul;
            return output;
        }
        else
        {
        for(int j=0;j<output.size();j++)
            if(nums[j] != 0)
                output[j] = mul/nums[j];
            else
                output[j] = mul;
        return output;            
        }
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);
        int leftmul = 1;
        int rightmul = 1;
        for(int i=0;i<nums.size();i++)
        {
            output[i] *= leftmul;
            leftmul *= nums[i];
        }
        for(int j=nums.size()-1;j>=0;j--)
        {
            output[j] *= rightmul;
            rightmul *= nums[j];
        }
        return output;
    }
};