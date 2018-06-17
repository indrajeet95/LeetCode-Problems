class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> ans;
        int target = nums.size()/2;
        cout << target;
        for(int i=0;i<nums.size();i++)
            ans[nums[i]]++;
        for(auto j=ans.begin();j!=ans.end();j++)
        {
            if(j->second > target)
                return j->first;
        }
    }
};
