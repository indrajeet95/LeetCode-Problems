//bruteforce solution O(N^3)

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                string temp = cutstring(s,i,j);
                if(ispalindrome(temp))
                    count++;
            }
        }
        return count;
    }
    bool ispalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        for(;i<=j;i++,j--)
            if(s[i] != s[j])
                return false;
        return true;
    }
    string cutstring(string s,int a,int b)
    {
        string res;
        for(int i = a;i<=b;i++)
            res.push_back(s[i]);
        return res;
    }
};

//A little bit smarter O(N^2)

class Solution {
public:
    int count = 0;
    int countSubstrings(string s) {
        for(int i = 0;i<s.size();i++)
        {
            ispalindrome(s,i,i);
            ispalindrome(s,i,i+1);
        }
        return count;
    }
    void ispalindrome(string s,int a,int b)
    {
        int left = a;
        int right = b;
        while(s[left] == s[right] && left>=0 && right<s.size())
        {
            count++;
            left--;
            right++;
        }
    }
};

