//DP problem similar to EDIT DISTANCE
//dp[i][j] represents cost of deletions to make s1[0 to i] and s2[0 to j] the same
//if the characters are same take the previous values, if not same, delete one character in s1 or delete one character in s2

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int ans[len1+1][len2+1];
        ans[0][0] = 0;
        for(int i=1;i<=len1;i++)
            ans[i][0]  = ans[i-1][0] + s1[i-1];
        for(int j=1;j<=len2;j++)
            ans[0][j] = ans[0][j-1] + s2[j-1];
        
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(s1[i-1] == s2[j-1])
                    ans[i][j] = ans[i-1][j-1];
                else
                {
                    ans[i][j] = min(ans[i-1][j] + s1[i-1],ans[i][j-1] + s2[j-1]);
                }
            }
        }
        return ans[len1][len2];
    }
};