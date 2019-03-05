class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //dp[i+1][j+1] handles max Alex could gain from games with values piles[i] to piles[j]
        //TO Note: how to find parity? Focusing on Alex. If it's Lee's turn you reduce points from the final score. 
        int n = piles.size();
        //vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        for(int N = 1; N <= n; N++) {
            for(int i=0, j = N-1; j<N; i++, j++) {
                int parity = (i + j + N)%2;
                if(parity) {
                    dp[i+1][j+1] = max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                }
                else {
                    dp[i+1][j+1] = min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
                }
            }            
        }
        return dp[1][n] > 0;
    }
};
