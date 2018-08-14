class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.size());
        int l_pos = S.find(C);
        int r_pos = S.rfind(C);
        int count = 1;
        for(int i=l_pos;i<S.size();i++)
        {
            if(S[i] == C)
            {
                res[i] = 0;
                count = 1;                
            }
            else
                res[i] = count++;
        }
        count = 1;
        for(int i=r_pos;i>=0;i--)
        {
            if(S[i] == C)
            {
                res[i] = 0;
                count = 1;
            }
            else if(i <= l_pos)
                res[i] = count++;
            else
                res[i] = min(res[i],count++);
        }
        return res;
    }
};
//1,2,3,0,1,0,0,1,2,3,4,0
//3,2,1,0,1,0,0,4,3,2,1,0

//1,2,1,0,1,0,0,1,2,2,1,0