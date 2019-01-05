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