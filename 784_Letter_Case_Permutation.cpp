class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S,0,res);
        return res;
    }
    void backtrack(string &S, int i, vector<string> &res)
    {
        if(i == S.size())
        {
            res.push_back(S);
            return;
        }
        backtrack(S,i+1,res);
        if(isalpha(S[i]))
        {
            S[i] ^= 1<<5;
            backtrack(S,i+1,res);
        }
    }
};