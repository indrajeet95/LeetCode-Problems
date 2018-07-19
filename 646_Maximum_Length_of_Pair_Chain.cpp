//DP problem
//sort the pairs based on the first element
//construct a dp array that contains max number of chains till i
//2 for loopsshould do the trick
//the max of current chains plus 1 and previous number of chains whichever is max
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int n = pairs.size();
        int dp[n];
        for(int k = 0;k<n;k++)
            dp[k] = 1;
        for(int i=1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        return dp[n-1];
    }
private:
    static bool cmp(vector<int>& a, vector<int>&b) {
        return a[0] < b[0];
    }
};