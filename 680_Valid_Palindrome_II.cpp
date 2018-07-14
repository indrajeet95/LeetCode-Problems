class Solution {
public:
    bool ispalindrome(string s,int i, int j)
    {
        for(;i<=j;i++,j--)
            if(s[i] != s[j])
                return false;
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        for(;i<=j;i++,j--)
            if(s[i] != s[j])
                return ispalindrome(s,i+1,j) || ispalindrome(s,i,j-1);
        return true;
    }
};