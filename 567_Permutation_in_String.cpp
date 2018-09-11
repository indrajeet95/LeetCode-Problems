class Solution {
public:
    bool flag = false;
    bool checkInclusion(string s1, string s2) {
        permute(s1,s2,0);
        return flag;
    }
    string swap(string s, int i,int j)
    {
        if(i == j)
            return s;
        string a = s.substr(0,i);
        string b = s.substr(i+1,j);
        string c = s.substr(j+1,s.length());
        return a + s[j] + b + s[i] + c;
    }
    void permute(string s1, string s2, int l)
    {
        if(s1.length() == l)
        {
            cout << "here";
            if(s2.find(s1) != string::npos)
                flag = true;
        }
        else
        {
            for(int i = l;i<s1.length();i++)
            {
                s1 = swap(s1,l,i);
                permute(s1,s2,l+1);
                s1 = swap(s1,l,i);
            }
        }
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        for(int i=0;i<=s2.length()-s1.length();i++)
        {
            string temp = s2.substr(i,s1.length());
            sort(temp.begin(),temp.end());
            if(temp.compare(s1) == 0)
                return true;
        }
        return false;
    }
};