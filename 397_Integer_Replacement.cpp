class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX)
            return 32;
        if(n==1)
            return 0;
        if(n%2==0)
            return 1 + integerReplacement(n/2);
        else
            return 1 + min(integerReplacement(n-1),integerReplacement(n+1));
    }
};

//memory limit exceeded solution
//logic seems to be good
//DP solution
//the trick is if we have an odd number we need to find dp[i+1] or dp[i-1] and go for the minimum
//however there is dp[i+1] since it has not been computed yet
//we can however turn 7 to 3 in two steps and on the other hand turn it into 4 in two steps.
//7 = 1step + 6 = 2steps + 3; 7 = 1step + 8 = 2steps + 4

class Solution {
public:
    int integerReplacement(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 0;
        for(int i=2;i<=n;i++)
            if(i%2==0)
                dp[i] = 1 + dp[i/2];
            else
                dp[i] = 2 + min(dp[i/2],dp[i/2+1]);
        return dp[n];
    }
};

//using hashmap since it is easy to retrieve the number of steps needed for a particular number
class Solution {
private:
    unordered_map<int, int> visited;

public:
    int integerReplacement(int n) {        
        if (n == 1) { return 0; }
        if (visited.count(n) == 0) {
            if (n & 1 == 1) {
                visited[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
            } else {
                visited[n] = 1 + integerReplacement(n / 2);
            }
        }
        return visited[n];
    }
};