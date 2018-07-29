class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = NULL;
        for(int i=0;i<s.size();i++)
            res ^= s[i];
        for(int j=0;j<t.size();j++)
            res ^= t[j];
        return res;
    }
};