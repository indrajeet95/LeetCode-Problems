class Solution {
public:
    // 1 3 4 2 
    //compare should return false to switch elements
    static bool compare(pair<int,int> a, pair<int,int> b)
    {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first && a.second < b.second;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int maxans;
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> V(envelopes.size(), 0);
        V[0] = 1;
        for(int i=1;i<envelopes.size();i++)
        {
            for(int j=0; j<i; j++)
            {
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                {
                    V[i] = max(V[i], V[j] + 1);
                    maxans = max(V[i], maxans);
                }
            }
        }
        return maxans;
    }
};