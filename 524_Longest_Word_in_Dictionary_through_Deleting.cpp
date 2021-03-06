class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int len = s.length();
        map<string,int> maps;
        for(int i=0;i<d.size();i++)
        {
            if(d[i].length()<=len)
                maps[d[i]] = d[i].length();
        }
        int max = 0;
        string res;
        for(auto it = maps.begin();it!=maps.end();it++)
        {
            int i=0,j=0;
            bool possible = false;
            while(i < s.length() && j < (it->first).length())
            {
                while(s[i] != it->first[j])
                    i++;
                if(s[i] == it->first[j])
                {
                    i++;
                    j++;
                }
            }
            if(j == (it->first).length())
                possible = true;
            if(max < it->first.length() && possible)
            {
                max = it->first.length();
                cout << it->first<<endl;
                res = it->first;
            }
        }
        return res;
    }
};

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for(int i=0;i<d.size();i++)
        {
            int l1=0,l2=0;
            bool possible = false;
            while(l1 < s.length() && l2 < d[i].length())
            {
                while(s[l1] != d[i][l2])
                    l1++;
                if(s[l1] == d[i][l2])
                {
                    l1++;
                    l2++;
                }
            }
            if(l2 == d[i].length())
                if(res.size() < d[i].size() || (res.size() == d[i].size() && res > d[i]))
                    res = d[i];
        }
        return res;
    }
};


class Solution {
public:
string findLongestWord(string s, vector<string>& d) {
        string ans;
        for(string word: d){
            int j=0,k=0;
            while(j<s.size() && k<word.size()){ 
                if(s[j]==word[k])
                    k++;
                j++;
            }
            int n=word.size();
            if(k==n && ((ans.size()==n && ans>word) || ans.size()<n))
                ans=word;
        }
        return ans;
    }
};