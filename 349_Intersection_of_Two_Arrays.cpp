class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> numsa;
        unordered_map<int,int> numsb;
        vector<int> res;
        for(auto it: nums1)
            numsa[it]++;
        for(auto it: nums2)
            numsb[it]++;
        for(auto a:nums1)
            if(numsa.count(a)>0 && numsb.count(a)>0 && find(res.begin(),res.end(),a) == res.end())
                res.push_back(a);
        return res;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> sets(nums1.begin(),nums1.end());
        for(auto x: nums2)
            if(sets.erase(x))
                res.push_back(x);
        return res;
    }
};