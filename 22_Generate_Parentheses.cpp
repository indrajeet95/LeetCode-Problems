class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("", res, n, 0);
        return res;
    }
    //n ->left paranthesis
    //m => right parenthesis
    void generate(string curr, vector<string> &res, int n, int m)
    {
        if(m == 0 && n == 0)
        {
            res.push_back(curr);
            return;
        }
        else
        {
            if(m>0)
                generate(curr + ')', res, n, m-1);
            if(n>0)
                generate(curr + '(', res, n-1, m+1);
        }
    }
};
