class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> counts;
        int counter = 0;
        for(auto it = nums.begin();it!=nums.end();it++)
        {
            counts[*it] = counter;
            counter++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(counts.count(target-nums[i])>0)
                if(counts.at(target-nums[i]) != i)
                {
                //cout << i;
                res.push_back(i);
                auto x = counts.find(target-nums[i]);
                //cout << x->second;
                res.push_back(x->second);
                return res;
                }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> map;
        for(int i=0; i<nums.size(); i++)
        {
            if(map.find(target - nums[i]) != map.end())
            {
                res.push_back(map[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return res;
    }
};