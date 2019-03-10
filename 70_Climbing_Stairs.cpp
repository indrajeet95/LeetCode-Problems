//recursive solution
//Time limit exceeded

class Solution {
public:
    int climbStairs(int n) {
        int res = climbSteps(0,n);
        return res;
    }
    int climbSteps(int i, int j) {
        if(i > j)
            return 0;
        else if(i == j)
            return 1;
        else
            return climbSteps(i+1, j) + climbSteps(i+2, j);
    }
};

//Dynamic Programming. 
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

//fibonaaci sequence

class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 1;
        int third;
        if(n == 0 || n == 1)
            return 1;
        for(int i=2;i<=n;i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};

// Can also solve with fibonaaci formula
