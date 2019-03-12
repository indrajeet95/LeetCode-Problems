class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)
            return 0;
        if(n == 1)
            return k;
        if(n == 2)
            return k*k;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = k;
        cout << dp[1] << " ";
        dp[2] = k*k;
        cout << dp[2] << " ";
        for(int i=3; i<=n; i++) {
            //two condns.
            //paint ith pole same as i-1th pole if allowed
            //paint ith pole different from i-1th pole
            //diff(i) = dp(i-1)*(k-1);
            //same(i) = diff(i-1)*1;
            //total(i) = diff(i) + same(i)
            //total(i) = total(i-1)*k-1 + diff(i-1)
            //total(i) = total(i-1)*k-1 + total(i-2)*k-1
            dp[i] = (k-1)*(dp[i-1] + dp[i-2]);
            cout << dp[i] << " ";
        }
        return dp[n];
    }
};
