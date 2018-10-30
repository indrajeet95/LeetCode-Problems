class Solution {
public:
    bool detectCapitalUse(string S) {
        if(S.size() == 0)
            return false;
        if(S.size() == 1)
            return true;
        int j;
        if(S[0] >= 'A' && S[0] <= 'Z')
        { 
            for(j=1; j<S.size() && S[j] >= 'A' && S[j] <= 'Z'; j++) { }
            if(j == S.size())
                return true;
            for(j=1; j<S.size() && S[j] >= 'a' && S[j] <= 'z'; j++) { }
            if(j == S.size())
                return true;
        }
        else if(S[0] >= 'a' && S[0] <= 'z')
        {
            for(j=1; j<S.size() && S[j] >= 'a' && S[j] <= 'z'; j++) { }
            if(j == S.size())
                return true;
        }
        return false;
    }
};