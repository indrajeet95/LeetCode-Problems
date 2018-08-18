class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char,int> maps;
        for(int i=0;i<S.length();i++)
            maps[S[i]] = i;
        int start = 0;
        int last = maps[S[0]];
        for(int j=0;j<S.length();j++)
        {
            last = max(maps[S[j]],last);
            if(last == j)
            {
                res.push_back(last-start+1);
                start = j+1;
            }
        }
        return res;
    }
};