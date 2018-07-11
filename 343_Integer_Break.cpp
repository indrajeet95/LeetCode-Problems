class Solution {
public:
    int integerBreak(int n) {
        if(n<=2)
            return 1;
        vector<int> res(n+1,0);
        //res[0] = 0;
        res[1] = 0;
        res[2] = 1;
        for(int i = 3;i<=n;i++)
        {
            for(int j = 1; j<i;j++)
            {
                res[i] = max(res[i],max(j*(i-j),j*res[i-j]));
            }
        }
        return res[n];
    }
};