class Solution {
public:
    //the concept is dynamic programming
    //we have a dp array which stores the number of arithmetic slices possible till that index
    //dp[3] gives the number of slices possible of variable lengths from 3 to 4.
    //the animation in solution should do the trick
    //if we have 2 slices possible till a certain element and by adding one more element at the end we still satify
    //the condition then we can we just need to increment 1 to the previous possible number of slices
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n,0);
        int sum = 0;
        if(n < 3)
            return 0;
        for(int i=2;i<n;i++)
        {
            if(A[i] - A[i-1] == A[i-1] - A[i-2])
            {
                dp[i] = dp[i-1] + 1;
                sum += dp[i];
            }
        }
        return sum;
    }
};