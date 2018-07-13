//my stupid soln
class Solution {
public:
    int minSteps(int n) {
        int res[1001];
        res[0]  = 0;
        res[1] = 0;
        res[2] = 2;
        for(int i=3;i<=n;i++)
        {
            res[i] = i;
        }
        for(int i=3;i<=n;i++)
        {
            vector<pair<int,int>> soln = factors(i);
            for(int j=0;j<soln.size();j++)
            {
                //cout << soln[j].first << soln[j].second;
                res[i] = min(res[i],res[soln[j].first] + soln[j].second);
            }
        }
        return res[n];
    }
    vector<pair<int,int>> factors(int n)
    {
        vector<pair<int,int>> ans;
        for(int i = 1;i<=n;i++)
        {
            if(n%i == 0)
            {
                ans.push_back(make_pair(i,n/i));
            }
        }
        return ans;
    }
};

//a better one apparently
class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        dp[1] = 0;
        for(int i=2;i<=n;i++)
        {
            dp[i] = i;
            for(int j=i-1;j>1;j--)
            {
                if(i%j == 0)
                {
                    dp[i] = dp[j] + i/j;
                    break;
                }
            }
        }
        return dp[n];
    }
};