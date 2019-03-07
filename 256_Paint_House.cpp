//O(1) Space Solution
//O(N) Time Solution

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(!n)
            return 0;
        if(n == 1)
            return min(costs[0][2],min(costs[0][0], costs[0][1]));
        for(int i=1; i<n; i++) {
            costs[i][0] = costs[i][0] + min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] = costs[i][1] + min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] = costs[i][2] + min(costs[i-1][0], costs[i-1][1]);
        }
        return min(costs[n-1][0], min(costs[n-1][1], costs[n-1][2]));
    }
};

//O(N2) Space Solution
//O(N) Time Solution

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs == NULL || costs.length() == 0 || costs[0].length() == 0) 
            return 0;
        int n = costs.size();
        cout << n << endl;
        vector<vector<int>> dp;
        if(n == 1)
            return min(costs[0][2],min(costs[0][0], costs[0][1]));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for(int i=1; i<n; i++) {
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};

