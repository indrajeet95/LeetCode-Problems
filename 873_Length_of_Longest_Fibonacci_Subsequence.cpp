class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> holder;
        int res = 0;
        for(int i=0; i<A.size(); i++)
            holder.insert(A[i]);
        for(int i=0; i<A.size(); i++)
        {
            for(int j=i+1; j<A.size(); j++)
            {
                int x = A[j];
                int y = A[i] + A[j];
                int pos_res = 2;
                while(holder.find(y) != holder.end())
                {
                    int news = x + y;
                    x = y;
                    y = news;
                    res = max(res,++pos_res);
                }
            }
        }
        return res>=3 ? res : 0;
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int res = 0;
        int n = A.size();
        unordered_map<int,int> maps;
        for(int i=0; i<A.size(); i++)
            maps[A[i]] = i;
        vector<vector<int>> dp(n, vector<int> (n,2));
        for(int j=1; j<n; j++)
        {
            for(int i=0; i<j; i++)
            {
                if(maps.find(A[j] - A[i]) != maps.end() && maps[A[j] - A[i]] < i)
                    dp[i][j] = max(dp[i][j], 1 + dp[maps[A[j] - A[i]]][i]);
            }
        }
        for(int i=0; i<n; i++)
            for(int j = 0; j<n; j++)
                res = max(res, dp[i][j]);
        return res>2?res:0;
    }
};