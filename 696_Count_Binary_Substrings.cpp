class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size() == 0)
            return 0;
        int preRun = 0;
        int curRun = 1;
        int res = 0;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == s[i-1])
                curRun++;
            else
            {
                preRun = curRun;
                curRun = 1;
            }
            if(preRun >= curRun)
                res++;
        }
        return res;
    }
};