class Solution {
public:
    //constructing the solution from n = 1 to n = 10001
    //two options for each set of same numbers. pick or skip
    //if you pick you have to skip the previous set of numbers and choose these ones
    //if you skip the current set, then you pick the previous set or skip the previous set as well
    int deleteAndEarn(vector<int>& nums) {
        vector<int> res(10001,0);
        for(auto it = nums.begin(); it!=nums.end();it++)
            res[*it] += *it;
        int skip = 0;
        int take = 0;
        for(int i=0;i<=10001;i++)
        {
            int takei = skip + res[i];
            int skipi = max(skip,take);
            take = takei;
            skip = skipi;
        }
        return max(skip,take);
    }
};
